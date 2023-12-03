#!/usr/bin/env python

# encola.py OUTS_DIR_BASE ID MIN_SEED MAX_SEED

from sys import argv, stdout
from os import getenv, environ, path, makedirs, getcwd, chdir, fdopen, chmod
import stat
from subprocess import Popen, PIPE
from tempfile import mkstemp
import math

if len(argv) < 3:
    raise "Faltan argumentos"

outs_dir_base=argv[1]
id=argv[2]

if len(argv) == 5:
    min_seed = int(argv[3])
    max_seed = int(argv[4])
elif len(argv) == 6:
    min_seed = int(argv[3])
    max_seed = int(argv[4])
    skip_set_file = argv[5]
elif len(argv) == 3:
    min_seed = 0
    max_seed = 0
elif len(argv) == 4:
    raise "min_seed especificado sin max_seed"
else:
    raise "Demasiados argumentos"

skip_set_file = None

pinexec = "~/Alexandra/pin-2.12-53271-gcc.4.4.7-ia32_intel64-linux/pin"
#pinexec = "~/pin-3.7-97619-g0d0c92f4f-gcc-linux/pin"
pintooldir = "~/Alexandra/pin-2.12-53271-gcc.4.4.7-ia32_intel64-linux/source/tools/ManualExamples/obj-intel64/"
#pintooldir = "~/pin-3.7-97619-g0d0c92f4f-gcc-linux/source/tools/ManualExamples/obj-intel64/"

sniperexec = "/home/users/aros/sniper/run-sniper"
sniperoptspre = "-cgainestown -crob -gperf_model/dram/num_controllers=1 -gperf_model/l3_cache/shared_cores="
sniperoptspost = " -gperf_model/l2_cache/perfect=true -gperf_model/l3_cache/perfect=true -gperf_model/l1_icache/perfect=true  -gperf_model/dram/direct_access=true -ggeneral/enable_icache_modeling=false -gperf_model/branch_predictor/type=none -gperf_model/l1_dcache/perfect=true -gclock_skew_minimization/barrier/quantum=2147483647 -gperf_model/dtlb/size=0 -gperf_model/core/interval_timer/window_size=256 -gperf_model/core/rob_timer/rs_entries=256 -gperf_model/core/rob_timer/outstanding_loads=256 -gperf_model/core/rob_timer/outstanding_stores=256 -gperf_model/core/rob_timer/commit_width=4 -gperf_model/core/rob_timer/deptrace=true -gperf_model/core/rob_timer/store_to_load_forwarding=false -gperf_model/core/rob_timer/deptrace_microops=true -gperf_model/core/rob_timer/deptrace_start_active=true -gperf_model/core/rob_timer/deptrace_roi=true"

#benchdir = "/home/users/aros/benchmarks/original/SpecCPU2017/CPU2017_BINS_NOHOOKS_STATIC_NOFAKE_ONELINK_MEGA/"
#benchdir = "/home/users/aros/benchmarks/original/SpecCPU2017/CPU2017_BINS_NOHOOKS_STATIC_6x_5x/"
#benchdir = "/home/users/aros/benchmarks/original/Huawei/"
benchdir = "/home/users/aros/benchmarks/original/GAP-github/"

vars = {
    "500.perlbench_1": ["500.perlbench_r", "./perlbench_r_base.GCC_7_3_0_HOOKS-m64 -I./lib checkspam_noprints.pl 2500 5 25 11 150 1 1 1 1 > perlbench_1.opts-O3.out 2>> perlbench_1.opts-O3.err"],
    "500.perlbench_2": ["500.perlbench_r", "./perlbench_r_base.GCC_7_3_0_HOOKS-m64 -I./lib diffmail_noprints.pl 4 800 10 17 19 300 > perlbench_2.opts-O3.out 2>> perlbench_2.opts-O3.err"],
    "500.perlbench_3": ["500.perlbench_r", "./perlbench_r_base.GCC_7_3_0_HOOKS-m64 -I./lib splitmail_noprints.pl 6400 12 26 16 100 0 > perlbench_3.opts-O3.out 2>> perlbench_3.opts-O3.err"],
    "502.gcc_1": ["502.gcc_r", "./cpugcc_r_base.GCC_7_3_0_HOOKS-m64 gcc-pp.c -O3 -finline-limit=0 -fif-conversion -fif-conversion2 -o gcc-pp.opts-O3_-finline-limit_0_-fif-conversion_-fif-conversion2.s > gcc-pp.opts-O3_-finline-limit_0_-fif-conversion_-fif-conversion2.out 2>> gcc-pp.opts-O3_-finline-limit_0_-fif-conversion_-fif-conversion2.err"],
    "502.gcc_2": ["502.gcc_r", "./cpugcc_r_base.GCC_7_3_0_HOOKS-m64 gcc-pp.c -O2 -finline-limit=36000 -fpic -o gcc-pp.opts-O2_-finline-limit_36000_-fpic.s > gcc-pp.opts-O2_-finline-limit_36000_-fpic.out 2>> gcc-pp.opts-O2_-finline-limit_36000_-fpic.err"],
    "502.gcc_3": ["502.gcc_r", "./cpugcc_r_base.GCC_7_3_0_HOOKS-m64 gcc-smaller.c -O3 -fipa-pta -o gcc-smaller.opts-O3_-fipa-pta.s > gcc-smaller.opts-O3_-fipa-pta.out 2>> gcc-smaller.opts-O3_-fipa-pta.err"],
    "502.gcc_4": ["502.gcc_r", "./cpugcc_r_base.GCC_7_3_0_HOOKS-m64 ref32.c -O5 -o ref32.opts-O5.s > ref32.opts-O5.out 2>> ref32.opts-O5.err"],
    "502.gcc_5": ["502.gcc_r", "./cpugcc_r_base.GCC_7_3_0_HOOKS-m64 ref32.c -O3 -fselective-scheduling -fselective-scheduling2 -o ref32.opts-O3_-fselective-scheduling_-fselective-scheduling2.s > ref32.opts-O3_-fselective-scheduling_-fselective-scheduling2.out 2>> ref32.opts-O3_-fselective-scheduling_-fselective-scheduling2.err"],
    "503.bwaves_1": ["503.bwaves_r", "./bwaves_r_base.GCC_7_3_0_HOOKS-m64 bwaves_1 < bwaves_1.in > bwaves_1.out 2>> bwaves_1.err"],
    "503.bwaves_2": ["503.bwaves_r", "./bwaves_r_base.GCC_7_3_0_HOOKS-m64 bwaves_2 < bwaves_2.in > bwaves_2.out 2>> bwaves_2.err"],
    "503.bwaves_3": ["503.bwaves_r", "./bwaves_r_base.GCC_7_3_0_HOOKS-m64 bwaves_3 < bwaves_3.in > bwaves_3.out 2>> bwaves_3.err"],
    "503.bwaves_4": ["503.bwaves_r", "./bwaves_r_base.GCC_7_3_0_HOOKS-m64 bwaves_4 < bwaves_4.in > bwaves_4.out 2>> bwaves_4.err"],
    "505.mcf": ["505.mcf_r", "./mcf_r_base.GCC_7_3_0_HOOKS-m64 inp.in > inp.out 2>> inp.err"],
    "507.cactuBSSN": ["507.cactuBSSN_r", "./cactusBSSN_r_base.GCC_7_3_0_HOOKS-m64 spec_ref.par > spec_ref.out 2>> spec_ref.err"],
    "508.namd": ["508.namd_r", "./namd_r_base.GCC_7_3_0_HOOKS-m64 --input apoa1.input --output apoa1.ref.output --iterations 65 > namd.out 2>> namd.err"],
    "510.parest": ["510.parest_r", "./parest_r_base.GCC_7_3_0_HOOKS-m64 ref.prm > ref.out 2>> ref.err"],
    "511.povray": ["511.povray_r", "./povray_r_base.GCC_7_3_0_HOOKS-m64 SPEC-benchmark-ref.ini > SPEC-benchmark-ref.stdout 2>> SPEC-benchmark-ref.stderr"],
    "519.lbm": ["519.lbm_r", "./lbm_r_base.GCC_7_3_0_HOOKS-m64 3000 reference.dat 0 0 100_100_130_ldc.of > lbm.out 2>> lbm.err"],
    "520.omnetpp": ["520.omnetpp_r", "./omnetpp_r_base.GCC_7_3_0_HOOKS-m64 -c General -r 0 > omnetpp.General-0.out 2>> omnetpp.General-0.err"],
    "521.wrf": ["521.wrf_r", "./wrf_r_base.GCC_7_3_0_HOOKS-m64 > rsl.out.0000 2>> wrf.err"],
    "523.xalancbmk": ["523.xalancbmk_r", "./cpuxalan_r_base.GCC_7_3_0_HOOKS-m64 -v t5.xml xalanc.xsl > ref-t5.out 2>> ref-t5.err"],
    "525.x264_1": ["525.x264_r", "./x264_r_base.GCC_7_3_0_HOOKS-m64 --pass 1 --stats x264_stats.log --bitrate 1000 --frames 1000 -o BuckBunny_New.264 BuckBunny.yuv 1280x720 > run_000-1000_x264_r_base.GCC_7_3_0_HOOKS-m64_x264_pass1.out 2>> run_000-1000_x264_r_base.GCC_7_3_0_HOOKS-m64_x264_pass1.err"],
    "525.x264_2": ["525.x264_r", "./x264_r_base.GCC_7_3_0_HOOKS-m64 --pass 2 --stats x264_stats.log --bitrate 1000 --dumpyuv 200 --frames 1000 -o BuckBunny_New.264 BuckBunny.yuv 1280x720 > run_000-1000_x264_r_base.GCC_7_3_0_HOOKS-m64_x264_pass2.out 2>> run_000-1000_x264_r_base.GCC_7_3_0_HOOKS-m64_x264_pass2.err"],
    "525.x264_3": ["525.x264_r", "./x264_r_base.GCC_7_3_0_HOOKS-m64 --seek 500 --dumpyuv 200 --frames 1250 -o BuckBunny_New.264 BuckBunny.yuv 1280x720 > run_0500-1250_x264_r_base.GCC_7_3_0_HOOKS-m64_x264.out 2>> run_0500-1250_x264_r_base.GCC_7_3_0_HOOKS-m64_x264.err"],
    "526.blender": ["526.blender_r", "./blender_r_base.GCC_7_3_0_HOOKS-m64 sh3_no_char.blend --render-output sh3_no_char_ --threads 1 -b -F RAWTGA -s 849 -e 849 -a > sh3_no_char.849.spec.out 2>> sh3_no_char.849.spec.err"],
    "527.cam4": ["527.cam4_r", "./cam4_r_base.GCC_7_3_0_HOOKS-m64 > cam4_r_base.GCC_7_3_0_HOOKS-m64.txt 2>> cam4_r_base.GCC_7_3_0_HOOKS-m64.err"],
    "531.deepsjeng": ["531.deepsjeng_r", "./deepsjeng_r_base.GCC_7_3_0_HOOKS-m64 ref.txt > ref.out 2>> ref.err"],
    "538.imagick": ["538.imagick_r", "./imagick_r_base.GCC_7_3_0_HOOKS-m64 -limit disk 0 refrate_input.tga -edge 41 -resample 181% -emboss 31 -colorspace YUV -mean-shift 19x19+15% -resize 30% refrate_output.tga > refrate_convert.out 2>> refrate_convert.err"],
    "541.leela": ["541.leela_r", "./leela_r_base.GCC_7_3_0_HOOKS-m64 ref.sgf > ref.out 2>> ref.err"],
    "544.nab": ["544.nab_r", "./nab_r_base.GCC_7_3_0_HOOKS-m64 1am0 1122214447 122 > 1am0.out 2>> 1am0.err"],
    "548.exchange2": ["548.exchange2_r", "./exchange2_r_base.GCC_7_3_0_HOOKS-m64 6 > exchange2.txt 2>> exchange2.err"],
    "549.fotonik3d": ["549.fotonik3d_r", "./fotonik3d_r_base.GCC_7_3_0_HOOKS-m64 > fotonik3d_r.log 2>> fotonik3d_r.err"],
    "554.roms": ["554.roms_r", "./roms_r_base.GCC_7_3_0_HOOKS-m64 < ocean_benchmark2.in.x > ocean_benchmark2.log 2>> ocean_benchmark2.err"], 
    "557.xz_1": ["557.xz_r", "./xz_r_base.GCC_7_3_0_HOOKS-m64 cld.tar.xz 160 19cf30ae51eddcbefda78dd06014b4b96281456e078ca7c13e1c0c9e6aaea8dff3efb4ad6b0456697718cede6bd5454852652806a657bb56e07d61128434b474 59796407 61004416 6 > cld.tar-160-6.out 2>> cld.tar-160-6.err"],
    "557.xz_2": ["557.xz_r", "./xz_r_base.GCC_7_3_0_HOOKS-m64 cpu2006docs.tar.xz 250 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 23047774 23513385 6e > cpu2006docs.tar-250-6e.out 2>> cpu2006docs.tar-250-6e.err"],
    "557.xz_3": ["557.xz_r", "./xz_r_base.GCC_7_3_0_HOOKS-m64 input.combined.xz 250 a841f68f38572a49d86226b7ff5baeb31bd19dc637a922a972b2e6d1257a890f6a544ecab967c313e370478c74f760eb229d4eef8a8d2836d233d3e9dd1430bf 40401484 41217675 7 > input.combined-250-7.out 2>> input.combined-250-7.err"],

    "600.perlbench_1": ["600.perlbench_s", "./perlbench_s_base.GCC_7_3_0-m64 -I./lib checkspam.pl 2500 5 25 11 150 1 1 1 1 > checkspam.2500.5.25.11.150.1.1.1.1.out 2>> checkspam.2500.5.25.11.150.1.1.1.1.err"],
    "600.perlbench_2": ["600.perlbench_s", "./perlbench_s_base.GCC_7_3_0-m64 -I./lib diffmail.pl 4 800 10 17 19 300 > diffmail.4.800.10.17.19.300.out 2>> diffmail.4.800.10.17.19.300.err"],
    "600.perlbench_3": ["600.perlbench_s", "./perlbench_s_base.GCC_7_3_0-m64 -I./lib splitmail.pl 6400 12 26 16 100 0 > splitmail.6400.12.26.16.100.0.out 2>> splitmail.6400.12.26.16.100.0.err"],
    "602.gcc_1": ["602.gcc_s", "./sgcc_base.GCC_7_3_0-m64 gcc-pp.c -O5 -fipa-pta -o gcc-pp.opts-O5_-fipa-pta.s > gcc-pp.opts-O5_-fipa-pta.out 2>> gcc-pp.opts-O5_-fipa-pta.err"],
    "602.gcc_2": ["602.gcc_s", "./sgcc_base.GCC_7_3_0-m64 gcc-pp.c -O5 -finline-limit=1000 -fselective-scheduling -fselective-scheduling2 -o gcc-pp.opts-O5_-finline-limit_1000_-fselective-scheduling_-fselective-scheduling2.s > gcc-pp.opts-O5_-finline-limit_1000_-fselective-scheduling_-fselective-scheduling2.out 2>> gcc-pp.opts-O5_-finline-limit_1000_-fselective-scheduling_-fselective-scheduling2.err"],
    "602.gcc_3": ["602.gcc_s", "./sgcc_base.GCC_7_3_0-m64 gcc-pp.c -O5 -finline-limit=24000 -fgcse -fgcse-las -fgcse-lm -fgcse-sm -o gcc-pp.opts-O5_-finline-limit_24000_-fgcse_-fgcse-las_-fgcse-lm_-fgcse-sm.s > gcc-pp.opts-O5_-finline-limit_24000_-fgcse_-fgcse-las_-fgcse-lm_-fgcse-sm.out 2>> gcc-pp.opts-O5_-finline-limit_24000_-fgcse_-fgcse-las_-fgcse-lm_-fgcse-sm.err"],
    "603.bwaves_1": ["603.bwaves_s", "./speed_bwaves_base.GCC_7_3_0-m64 bwaves_1 < bwaves_1.in > bwaves_1.out 2>> bwaves_1.err"],
    "603.bwaves_2": ["603.bwaves_s", "./speed_bwaves_base.GCC_7_3_0-m64 bwaves_2 < bwaves_2.in > bwaves_2.out 2>> bwaves_2.err"],
    "605.mcf": ["605.mcf_s", "./mcf_s_base.GCC_7_3_0-m64 inp.in  > inp.out 2>> inp.err"],
    "607.cactuBSSN": ["607.cactuBSSN_s", "./cactuBSSN_s_base.GCC_7_3_0-m64 spec_ref.par   > spec_ref.out 2>> spec_ref.err"],
    "619.lbm": ["619.lbm_s", "./lbm_s_base.GCC_7_3_0-m64 2000 reference.dat 0 0 200_200_260_ldc.of > lbm.out 2>> lbm.err"],
    "620.omnetpp": ["620.omnetpp_s", "./omnetpp_s_base.GCC_7_3_0-m64 -c General -r 0 > omnetpp.General-0.out 2>> omnetpp.General-0.err"],
    "621.wrf": ["621.wrf_s", "./wrf_s_base.GCC_7_3_0-m64 > rsl.out.0000 2>> wrf.err"],
    "623.xalancbmk": ["623.xalancbmk_s", "./xalancbmk_s_base.GCC_7_3_0-m64 -v t5.xml xalanc.xsl > ref-t5.out 2>> ref-t5.err"],
    "625.x264_1": ["625.x264_s", "./x264_s_base.GCC_7_3_0-m64 --pass 1 --stats x264_stats.log --bitrate 1000 --frames 1000 -o BuckBunny_New.264 BuckBunny.yuv 1280x720 > run_000-1000_x264_s_base.GCC_7_3_0-m64_x264_pass1.out 2>> run_000-1000_x264_s_base.GCC_7_3_0-m64_x264_pass1.err"],
    "625.x264_2": ["625.x264_s", "./x264_s_base.GCC_7_3_0-m64 --pass 2 --stats x264_stats.log --bitrate 1000 --dumpyuv 200 --frames 1000 -o BuckBunny_New.264 BuckBunny.yuv 1280x720 > run_000-1000_x264_s_base.GCC_7_3_0-m64_x264_pass2.out 2>> run_000-1000_x264_s_base.GCC_7_3_0-m64_x264_pass2.err"],
    "625.x264_3": ["625.x264_s", "./x264_s_base.GCC_7_3_0-m64 --seek 500 --dumpyuv 200 --frames 1250 -o BuckBunny_New.264 BuckBunny.yuv 1280x720 > run_0500-1250_x264_s_base.GCC_7_3_0-m64_x264.out 2>> run_0500-1250_x264_s_base.GCC_7_3_0-m64_x264.err"],
    "627.cam4": ["627.cam4_s", "./cam4_s_base.GCC_7_3_0-m64 > cam4_s_base.GCC_7_3_0-m64.txt 2>> cam4_s_base.GCC_7_3_0-m64.err"],
    "628.pop2": ["628.pop2_s", "./speed_pop2_base.GCC_7_3_0-m64 > pop2_s.out 2>> pop2_s.err"],
    "631.deepsjeng": ["631.deepsjeng_s", "./deepsjeng_s_base.GCC_7_3_0-m64 ref.txt > ref.out 2>> ref.err"],
    "638.imagick": ["638.imagick_s", "./imagick_s_base.GCC_7_3_0-m64 -limit disk 0 refspeed_input.tga -resize 817% -rotate -2.76 -shave 540x375 -alpha remove -auto-level -contrast-stretch 1x1% -colorspace Lab -channel R -equalize +channel -colorspace sRGB -define histogram:unique-colors=false -adaptive-blur 0x5 -despeckle -auto-gamma -adaptive-sharpen 55 -enhance -brightness-contrast 10x10 -resize 30% refspeed_output.tga > refspeed_convert.out 2>> refspeed_convert.err"],
    "641.leela": ["641.leela_s", "./leela_s_base.GCC_7_3_0-m64 ref.sgf > ref.out 2>> ref.err"],
    "644.nab": ["644.nab_s", "./nab_s_base.GCC_7_3_0-m64 3j1n 20140317 220 > 3j1n.out 2>> 3j1n.err"],
    "648.exchange2": ["648.exchange2_s", "./exchange2_s_base.GCC_7_3_0-m64 6 > exchange2.txt 2>> exchange2.err"],
    "649.fotonik3d": ["649.fotonik3d_s", "./fotonik3d_s_base.GCC_7_3_0-m64 > fotonik3d_s.log 2>> fotonik3d_s.err"],
    "654.roms": ["654.roms_s", "./sroms_base.GCC_7_3_0-m64 < ocean_benchmark3.in > ocean_benchmark3.log 2>> ocean_benchmark3.err"],
    "657.xz_1": ["657.xz_s", "./xz_s_base.GCC_7_3_0-m64 cpu2006docs.tar.xz 6643 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 1036078272 1111795472 4 > cpu2006docs.tar-6643-4.out 2>> cpu2006docs.tar-6643-4.err"],
    "657.xz_2": ["657.xz_s", "./xz_s_base.GCC_7_3_0-m64 cld.tar.xz 1400 19cf30ae51eddcbefda78dd06014b4b96281456e078ca7c13e1c0c9e6aaea8dff3efb4ad6b0456697718cede6bd5454852652806a657bb56e07d61128434b474 536995164 539938872 8 > cld.tar-1400-8.out 2>> cld.tar-1400-8.err"],
    
    # "600.perlbench": ["600.perlbench_s", "./run_600.perlbench_s.sh"],
    # "602.gcc": ["602.gcc_s", "./run_602.gcc_s.sh"],
    # "603.bwaves": ["603.bwaves_s", "./run_603.bwaves_s.sh"],
    # "605.mcf": ["605.mcf_s", "./run_605.mcf_s.sh"],
    # "607.cactuBSSN": ["607.cactuBSSN_s", "./run_607.cactuBSSN_s.sh"],
    # "619.lbm": ["619.lbm_s", "./run_619.lbm_s.sh"],
    # "620.omnetpp": ["620.omnetpp_s", "./run_620.omnetpp_s.sh"],
    # "621.wrf": ["621.wrf_s", "./run_621.wrf_s.sh"],
    # "623.xalancbmk": ["623.xalancbmk_s", "./run_623.xalancbmk_s.sh"],
    # "625.x264": ["625.x264_s", "./run_625.x264_s.sh"],
    # "627.cam4": ["627.cam4_s", "./run_627.cam4_s.sh"],
    # "628.pop2": ["628.pop2_s", "./run_628.pop2_s.sh"],
    # "631.deepsjeng": ["631.deepsjeng_s", "./run_631.deepsjeng_s.sh"],
    # "638.imagick": ["638.imagick_s", "./run_638.imagick_s.sh"],
    # "641.leela": ["641.leela_s", "./run_641.leela_s.sh"],
    # "644.nab": ["644.nab_s", "./run_644.nab_s.sh"],
    # "648.exchange2": ["648.exchange2_s", "./run_648.exchange2_s.sh"],
    # "649.fotonik3d": ["649.fotonik3d_s", "./run_649.fotonik3d_s.sh"],
    # "654.roms": ["654.roms_s", "./run_654.roms_s.sh"],
    # "657.xz": ["657.xz_s", "./run_657.xz_s.sh"],
    
    "Benchmark1": [".", "./Benchmark1"],
    "Benchmark2": [".", "./Benchmark2"],
    "Benchmark3": [".", "./Benchmark3"],

    "bc-kron": [".", "./bc -f benchmark/graphs/kron.sg -i4 -n16"],
    "bc-road": [".", "./bc -f benchmark/graphs/road.sg -i4 -n16"],
    "bc-twitter": [".", "./bc -f benchmark/graphs/twitter.sg -i4 -n16"],
    "bc-urand": [".", "./bc -f benchmark/graphs/urand.sg -i4 -n16"],
    "bc-web": [".", "./bc -f benchmark/graphs/web.sg -i4 -n16"],
 
    "bfs-kron": [".", "./bfs -f benchmark/graphs/kron.sg -n64"],
    "bfs-road": [".", "./bfs -f benchmark/graphs/road.sg -n64"],
    "bfs-twitter": [".", "./bfs -f benchmark/graphs/twitter.sg -n64"],
    "bfs-urand": [".", "./bfs -f benchmark/graphs/urand.sg -n64"],
    "bfs-web": [".", "./bfs -f benchmark/graphs/web.sg -n64"],

    "cc-kron": [".", "./cc -f benchmark/graphs/kron.sg -n16"],
    "cc-road": [".", "./cc -f benchmark/graphs/road.sg -n16"],
    "cc-twitter": [".", "./cc -f benchmark/graphs/twitter.sg -n16"],
    "cc-urand": [".", "./cc -f benchmark/graphs/urand.sg -n16"],
    "cc-web": [".", "./cc -f benchmark/graphs/web.sg -n16"],

    "pr-kron": [".", "./pr -f benchmark/graphs/kron.sg -i1000 -t1e-4 -n16"],
    "pr-road": [".", "./pr -f benchmark/graphs/road.sg -i1000 -t1e-4 -n16"],
    "pr-twitter": [".", "./pr -f benchmark/graphs/twitter.sg -i1000 -t1e-4 -n16"],
    "pr-urand": [".", "./pr -f benchmark/graphs/urand.sg -i1000 -t1e-4 -n16"],
    "pr-web": [".", "./pr -f benchmark/graphs/web.sg -i1000 -t1e-4 -n16"],

    "sssp-kron": [".", "./sssp -f benchmark/graphs/kron.wsg -n64 -d2"],
    "sssp-road": [".", "./sssp -f benchmark/graphs/road.wsg -n64 -d50000"],
    "sssp-twitter": [".", "./sssp -f benchmark/graphs/twitter.wsg -n64 -d2"],
    "sssp-urand": [".", "./sssp -f benchmark/graphs/urand.wsg -n64 -d2"],
    "sssp-web": [".", "./sssp -f benchmark/graphs/web.wsg -n64 -d2"],

    "tc-kron": [".", "./tc -f benchmark/graphs/kronU.sg -n3"],
    "tc-road": [".", "./tc -f benchmark/graphs/roadU.sg -n3"],
    "tc-twitter": [".", "./tc -f benchmark/graphs/twitterU.sg -n3"],
    "tc-urand": [".", "./tc -f benchmark/graphs/urandU.sg -n3"],
    "tc-web": [".", "./tc -f benchmark/graphs/webU.sg -n3"],

    }

if not path.isdir(outs_dir_base):
    raise "no existe el directorio: '" + outs_dir_base + "'"

if getenv("ENCOLA_JUST_TEST", "0") == "1":
    just_test = 1
else:
    just_test = 0

if skip_set_file == None:
    skip_set = set()
else:
    skip_set = set([l.strip() for l in open(skip_set_file)])

def merge_dicts (d1, d2):
    ret = d1.copy()
    ret.update(d2)
    return ret

base_config = {
    "BENCHMARK": "",
    "NUM_THREADS": 1,
    "PINTOOL": "inscount0",
    "TRACE_SIZE_NAME": "ref",
    }

def out_file(config):
#    return path.join(outs_dir_base, "%s_%s" % (config["BENCHMARK"], config["TRACE_SIZE_NAME"]))
    return path.join(outs_dir_base, "%s_%s" % (config["BENCHMARK"], config["PINTOOL"]))
#    return path.join(outs_dir_base, "%s_%s" % (config["BENCHMARK"], config["INPUT"]))

def enqueue(config):
    def quote(s):
        return s.replace("\"", "\\\"")

    of = out_file(config)

    if not path.isdir(path.dirname(of)):
        makedirs(path.dirname(of))

    if path.exists(of + ".stderr"):
        print "skipped %s (%s exists)" % (path.basename(of), of + ".stderr")
    elif path.basename(of) in skip_set:
        print "skipped %s (in skip_set)" % path.basename(of)
    else:

        def write_script(f):
            f.write("ulimit -c0\n")
            f.write("export OMP_NUM_THREADS=" + str(config["NUM_THREADS"]) + "\n")
            f.write("cd " + benchdir + vars[config["BENCHMARK"]][0] + "\n")
            f.write(pinexec + " -t " + pintooldir + config["PINTOOL"] + ".so" + " -o " + out_file(config) + " -- " + vars[config["BENCHMARK"]][1] + "\n")
            #f.write(pinexec + " -t " + pintooldir + config["PINTOOL"] + ".so" + " -o " + out_file(config) + " -- " + vars[config["BENCHMARK"]][1] + " " + str(config["INPUT"]) + "\n")

        if just_test == 0:
            p = Popen(["qsub", "-cwd", "-N", id + path.basename(of), "-r", "yes", "-V", "-e", of + ".stderr", "-o", of + ".stdout"], stdin = PIPE)
            #p = Popen(["qsub", "-cwd", "-N", id + path.basename(of), "-r", "yes", "-V", "-e", of + ".stderr", "-o", of + ".stdout", "-q", "short.q"], stdin = PIPE)
            write_script(p.stdin)
            p.stdin.close()
            p.wait()
        else:
            (fdes, fname) = mkstemp()
            f = fdopen(fdes, "w")
            f.write("#!/bin/bash\n")
            f.write("pushd .\n")
            write_script(f)
            f.write("popd\n")
            f.close()
            chmod(fname, stat.S_IRUSR | stat.S_IWUSR | stat.S_IXUSR)
            print "Created test script %s for %s" % (fname, path.basename(of))
        

def config_vary(base, key, values, guard = lambda c: True):
    ret = []
    if type(base) == list:
        for b in base:
            if guard(b):
                ret += config_vary(b, key, values)
            else:
                ret.append(b)
        return ret
    for v in values:
        c = base.copy()
        if type(key) == tuple:
            for (k, sv) in zip(key, v):
                c[k] = sv
                ret.append(c)
        else:
            c[key] = v
            ret.append(c)
    return ret

def remove_duplicates(l):
    r = []
    for i in l:
        if not i in r:
            r.append(i)
    return r

def check_duplicate_output_files(l):
    m = {}
    for c in l:
        of = out_file(c)
        m.setdefault(of, [])
        m[of].append(c)
    for i in m:
        if len(m[i]) != 1:
            raise "Duplicate out_file: %s, %s" % (i, str(m[i]))

# do not modify
configs = config_vary(base_config, "g_RANDOM_SEED", range(min_seed, max_seed + 1))

# modify if necessary
configs = config_vary(configs, "BENCHMARK", [ 
        # "500.perlbench_1",
        # "500.perlbench_2",
        # "500.perlbench_3",
        # "502.gcc_1",
        # "502.gcc_2",
        # "502.gcc_3",
        # "502.gcc_4",
        # "502.gcc_5",
        # "503.bwaves_1",
        # "503.bwaves_2",
        # "503.bwaves_3",
        # "503.bwaves_4",
        # "505.mcf",
        # "507.cactuBSSN",
        # "508.namd",
        # "510.parest",
        # "511.povray",
        # "519.lbm",
        # "520.omnetpp",
        # "521.wrf",
        # "523.xalancbmk",
        # "525.x264_1",
        # "525.x264_2",
        # "525.x264_3",
        # "526.blender",
        # "527.cam4",
        # "531.deepsjeng",
        # "538.imagick",
        # "541.leela",
        # "544.nab",
        # "548.exchange2",
        # "549.fotonik3d",
        # "554.roms",
        # "557.xz_1",
        # "557.xz_2",
        # "557.xz_3",

        # "600.perlbench_1",
        # "600.perlbench_2",
        # "600.perlbench_3",
        # # "600.perlbench",
        # "602.gcc_1",
        # "602.gcc_2",
        # "602.gcc_3",
        # #"602.gcc",
        # "603.bwaves_1",
        # "603.bwaves_2",
        # #"603.bwaves",
        # "605.mcf",
        # "607.cactuBSSN",
        # "619.lbm",
        # "620.omnetpp",
        # "621.wrf",
        # "623.xalancbmk",
        # "625.x264_1",
        # "625.x264_2",
        # "625.x264_3",
        # #"625.x264",
        # "627.cam4",
        # "628.pop2",
        # "631.deepsjeng",
        # "638.imagick",
        # "641.leela",
        # "644.nab",
        # "648.exchange2",
        # "649.fotonik3d",
        # "654.roms",
        # "657.xz_1",
        # "657.xz_2",
        # #"657.xz",

        # "Benchmark1",
        # "Benchmark2",
        # "Benchmark3",

        # GAP
        "bc-kron",
        "bc-road",
        "bc-twitter",
        "bc-urand",
        "bc-web",
        
        "bfs-kron",
        "bfs-road",
        "bfs-twitter",
        "bfs-urand",
        "bfs-web",

        "cc-kron",
        "cc-road",
        "cc-twitter",
        "cc-urand",
        "cc-web",

        "pr-kron",
        "pr-road",
        "pr-twitter",
        "pr-urand",
        "pr-web",

        "sssp-kron",
        "sssp-road",
        "sssp-twitter",
        "sssp-urand",
        "sssp-web",

        "tc-kron",
        "tc-road",
        "tc-twitter",
        "tc-urand",
        "tc-web",

    ])

#configs = config_vary(configs, "INPUT", [ 100, 200, 400, 800, 1600, 6400, 12800 ])

configs = config_vary(configs, "PINTOOL", [ 
        # "inscount0",
        "inscount2",
        ])

configs = remove_duplicates(configs)
check_duplicate_output_files(configs)

for c in configs:
    enqueue(c)
