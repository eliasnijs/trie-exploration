desc: --stacks=yes --massif-out-file=memory.ms
cmd: build/build
time_unit: i
#-----------
snapshot=0
#-----------
time=0
mem_heap_B=0
mem_heap_extra_B=0
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=1
#-----------
time=232049
mem_heap_B=154094757
mem_heap_extra_B=2355
mem_stacks_B=704
heap_tree=detailed
n2: 154094757 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n0: 5608 in 7 places, all below massif's threshold (1.00%)
#-----------
snapshot=2
#-----------
time=1858021753
mem_heap_B=154090189
mem_heap_extra_B=2331
mem_stacks_B=632
heap_tree=empty
#-----------
snapshot=3
#-----------
time=1858021806
mem_heap_B=168040565
mem_heap_extra_B=2875
mem_stacks_B=704
heap_tree=detailed
n3: 168040565 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 7 places, all below massif's threshold (1.00%)
#-----------
snapshot=4
#-----------
time=2654624521
mem_heap_B=168040565
mem_heap_extra_B=2875
mem_stacks_B=576
heap_tree=empty
#-----------
snapshot=5
#-----------
time=3096051909
mem_heap_B=210320805
mem_heap_extra_B=13935211
mem_stacks_B=752
heap_tree=detailed
n6: 210320805 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 23722720 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 23722720 0x10C5A3: trie_add (trie.c:110)
   n1: 23722720 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 23722720 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 23722720 0x111AD0: main_tests (main.c:95)
      n0: 23722720 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n1: 12774600 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 12774600 0x10C5A3: trie_add (trie.c:110)
   n1: 12774600 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 12774600 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 12774600 0x111AD0: main_tests (main.c:95)
      n0: 12774600 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 5782920 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 5782920 0x10C5A3: trie_add (trie.c:110)
   n1: 5782920 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 5782920 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 5782920 0x111AD0: main_tests (main.c:95)
      n0: 5782920 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=6
#-----------
time=3476873408
mem_heap_B=239804216
mem_heap_extra_B=23154640
mem_stacks_B=752
heap_tree=detailed
n6: 239804216 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 37178920 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 37178920 0x10C5A3: trie_add (trie.c:110)
   n1: 37178920 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 37178920 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 37178920 0x111AD0: main_tests (main.c:95)
      n0: 37178920 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 23809451 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 23809451 0x10C5A3: trie_add (trie.c:110)
   n1: 23809451 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 23809451 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 23809451 0x111AD0: main_tests (main.c:95)
      n0: 23809451 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n1: 10775280 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 10775280 0x10C5A3: trie_add (trie.c:110)
   n1: 10775280 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 10775280 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 10775280 0x111AD0: main_tests (main.c:95)
      n0: 10775280 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=7
#-----------
time=3784139518
mem_heap_B=262990871
mem_heap_extra_B=30384665
mem_stacks_B=752
heap_tree=detailed
n6: 262990871 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 47637600 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 47637600 0x10C5A3: trie_add (trie.c:110)
   n1: 47637600 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 47637600 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 47637600 0x111AD0: main_tests (main.c:95)
      n0: 47637600 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 32573386 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 32573386 0x10C5A3: trie_add (trie.c:110)
   n1: 32573386 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 32573386 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 32573386 0x111AD0: main_tests (main.c:95)
      n0: 32573386 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 14739320 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 14739320 0x10C5A3: trie_add (trie.c:110)
   n1: 14739320 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 14739320 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 14739320 0x111AD0: main_tests (main.c:95)
      n0: 14739320 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=8
#-----------
time=4028708816
mem_heap_B=281491244
mem_heap_extra_B=36192788
mem_stacks_B=752
heap_tree=detailed
n6: 281491244 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 56225480 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 56225480 0x10C5A3: trie_add (trie.c:110)
   n1: 56225480 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 56225480 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 56225480 0x111AD0: main_tests (main.c:95)
      n0: 56225480 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 39398119 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 39398119 0x10C5A3: trie_add (trie.c:110)
   n1: 39398119 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 39398119 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 39398119 0x111AD0: main_tests (main.c:95)
      n0: 39398119 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 17827080 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 17827080 0x10C5A3: trie_add (trie.c:110)
   n1: 17827080 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 17827080 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 17827080 0x111AD0: main_tests (main.c:95)
      n0: 17827080 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=9
#-----------
time=4292880051
mem_heap_B=301501121
mem_heap_extra_B=42505447
mem_stacks_B=752
heap_tree=detailed
n6: 301501121 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 65696440 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 65696440 0x10C5A3: trie_add (trie.c:110)
   n1: 65696440 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 65696440 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 65696440 0x111AD0: main_tests (main.c:95)
      n0: 65696440 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 46650516 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 46650516 0x10C5A3: trie_add (trie.c:110)
   n1: 46650516 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 46650516 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 46650516 0x111AD0: main_tests (main.c:95)
      n0: 46650516 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 21113600 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 21113600 0x10C5A3: trie_add (trie.c:110)
   n1: 21113600 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 21113600 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 21113600 0x111AD0: main_tests (main.c:95)
      n0: 21113600 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=10
#-----------
time=4574816608
mem_heap_B=323134554
mem_heap_extra_B=49375630
mem_stacks_B=752
heap_tree=detailed
n6: 323134554 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 76225080 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 76225080 0x10C5A3: trie_add (trie.c:110)
   n1: 76225080 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 76225080 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 76225080 0x111AD0: main_tests (main.c:95)
      n0: 76225080 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 54295669 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 54295669 0x10C5A3: trie_add (trie.c:110)
   n1: 54295669 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 54295669 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 54295669 0x111AD0: main_tests (main.c:95)
      n0: 54295669 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 24573240 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 24573240 0x10C5A3: trie_add (trie.c:110)
   n1: 24573240 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 24573240 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 24573240 0x111AD0: main_tests (main.c:95)
      n0: 24573240 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=11
#-----------
time=4877266354
mem_heap_B=346519137
mem_heap_extra_B=56856311
mem_stacks_B=752
heap_tree=detailed
n6: 346519137 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 87939040 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 87939040 0x10C5A3: trie_add (trie.c:110)
   n1: 87939040 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 87939040 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 87939040 0x111AD0: main_tests (main.c:95)
      n0: 87939040 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 62327652 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 62327652 0x10C5A3: trie_add (trie.c:110)
   n1: 62327652 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 62327652 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 62327652 0x111AD0: main_tests (main.c:95)
      n0: 62327652 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 28211880 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 28211880 0x10C5A3: trie_add (trie.c:110)
   n1: 28211880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 28211880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 28211880 0x111AD0: main_tests (main.c:95)
      n0: 28211880 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=12
#-----------
time=5327116194
mem_heap_B=381791975
mem_heap_extra_B=68241745
mem_stacks_B=752
heap_tree=detailed
n6: 381791975 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 106250360 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 106250360 0x10C5A3: trie_add (trie.c:110)
   n1: 106250360 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 106250360 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 106250360 0x111AD0: main_tests (main.c:95)
      n0: 106250360 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 74004690 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 74004690 0x10C5A3: trie_add (trie.c:110)
   n1: 74004690 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 74004690 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 74004690 0x111AD0: main_tests (main.c:95)
      n0: 74004690 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 33496360 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 33496360 0x10C5A3: trie_add (trie.c:110)
   n1: 33496360 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 33496360 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 33496360 0x111AD0: main_tests (main.c:95)
      n0: 33496360 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=13
#-----------
time=5678894355
mem_heap_B=409921726
mem_heap_extra_B=77400570
mem_stacks_B=752
heap_tree=detailed
n6: 409921726 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 121351240 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 121351240 0x10C5A3: trie_add (trie.c:110)
   n1: 121351240 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 121351240 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 121351240 0x111AD0: main_tests (main.c:95)
      n0: 121351240 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 82976481 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 82976481 0x10C5A3: trie_add (trie.c:110)
   n1: 82976481 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 82976481 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 82976481 0x111AD0: main_tests (main.c:95)
      n0: 82976481 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 37553440 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 37553440 0x10C5A3: trie_add (trie.c:110)
   n1: 37553440 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 37553440 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 37553440 0x111AD0: main_tests (main.c:95)
      n0: 37553440 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=14
#-----------
time=6054603806
mem_heap_B=440326772
mem_heap_extra_B=87373860
mem_stacks_B=752
heap_tree=detailed
n6: 440326772 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 138126320 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 138126320 0x10C5A3: trie_add (trie.c:110)
   n1: 138126320 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 138126320 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 138126320 0x111AD0: main_tests (main.c:95)
      n0: 138126320 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 92359127 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 92359127 0x10C5A3: trie_add (trie.c:110)
   n1: 92359127 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 92359127 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 92359127 0x111AD0: main_tests (main.c:95)
      n0: 92359127 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 41800760 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 41800760 0x10C5A3: trie_add (trie.c:110)
   n1: 41800760 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 41800760 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 41800760 0x111AD0: main_tests (main.c:95)
      n0: 41800760 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=15
#-----------
time=6454380988
mem_heap_B=473192140
mem_heap_extra_B=98232436
mem_stacks_B=752
heap_tree=detailed
n6: 473192140 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 156745440 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 156745440 0x10C5A3: trie_add (trie.c:110)
   n1: 156745440 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 156745440 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 156745440 0x111AD0: main_tests (main.c:95)
      n0: 156745440 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 102166535 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 102166535 0x10C5A3: trie_add (trie.c:110)
   n1: 102166535 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 102166535 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 102166535 0x111AD0: main_tests (main.c:95)
      n0: 102166535 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 46239600 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 46239600 0x10C5A3: trie_add (trie.c:110)
   n1: 46239600 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 46239600 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 46239600 0x111AD0: main_tests (main.c:95)
      n0: 46239600 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=16
#-----------
time=6880179145
mem_heap_B=508713053
mem_heap_extra_B=110058203
mem_stacks_B=752
heap_tree=detailed
n6: 508713053 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 177409720 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 177409720 0x10C5A3: trie_add (trie.c:110)
   n1: 177409720 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 177409720 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 177409720 0x111AD0: main_tests (main.c:95)
      n0: 177409720 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 112385688 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 112385688 0x10C5A3: trie_add (trie.c:110)
   n1: 112385688 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 112385688 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 112385688 0x111AD0: main_tests (main.c:95)
      n0: 112385688 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 50877080 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 50877080 0x10C5A3: trie_add (trie.c:110)
   n1: 50877080 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 50877080 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 50877080 0x111AD0: main_tests (main.c:95)
      n0: 50877080 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=17
#-----------
time=7102773520
mem_heap_B=527537101
mem_heap_extra_B=116358939
mem_stacks_B=752
heap_tree=detailed
n6: 527537101 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 188582240 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 188582240 0x10C5A3: trie_add (trie.c:110)
   n1: 188582240 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 188582240 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 188582240 0x111AD0: main_tests (main.c:95)
      n0: 188582240 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 117653456 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 117653456 0x10C5A3: trie_add (trie.c:110)
   n1: 117653456 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 117653456 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 117653456 0x111AD0: main_tests (main.c:95)
      n0: 117653456 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 53260840 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 53260840 0x10C5A3: trie_add (trie.c:110)
   n1: 53260840 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 53260840 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 53260840 0x111AD0: main_tests (main.c:95)
      n0: 53260840 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=18
#-----------
time=7332820743
mem_heap_B=547110134
mem_heap_extra_B=122930858
mem_stacks_B=752
heap_tree=detailed
n6: 547110134 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 200327800 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 200327800 0x10C5A3: trie_add (trie.c:110)
   n1: 200327800 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 200327800 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 200327800 0x111AD0: main_tests (main.c:95)
      n0: 200327800 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 123043169 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 123043169 0x10C5A3: trie_add (trie.c:110)
   n1: 123043169 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 123043169 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 123043169 0x111AD0: main_tests (main.c:95)
      n0: 123043169 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 55698600 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 55698600 0x10C5A3: trie_add (trie.c:110)
   n1: 55698600 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 55698600 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 55698600 0x111AD0: main_tests (main.c:95)
      n0: 55698600 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=19
#-----------
time=7570372860
mem_heap_B=567462127
mem_heap_extra_B=129785345
mem_stacks_B=752
heap_tree=detailed
n6: 567462127 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 212668800 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 212668800 0x10C5A3: trie_add (trie.c:110)
   n1: 212668800 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 212668800 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 212668800 0x111AD0: main_tests (main.c:95)
      n0: 212668800 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 128557842 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 128557842 0x10C5A3: trie_add (trie.c:110)
   n1: 128557842 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 128557842 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 128557842 0x111AD0: main_tests (main.c:95)
      n0: 128557842 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 58194920 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 58194920 0x10C5A3: trie_add (trie.c:110)
   n1: 58194920 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 58194920 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 58194920 0x111AD0: main_tests (main.c:95)
      n0: 58194920 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=20
#-----------
time=7815409251
mem_heap_B=588618527
mem_heap_extra_B=136940113
mem_stacks_B=752
heap_tree=detailed
n6: 588618527 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 225678040 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 225678040 0x10C5A3: trie_add (trie.c:110)
   n1: 225678040 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 225678040 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 225678040 0x111AD0: main_tests (main.c:95)
      n0: 225678040 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 134165162 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 134165162 0x10C5A3: trie_add (trie.c:110)
   n1: 134165162 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 134165162 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 134165162 0x111AD0: main_tests (main.c:95)
      n0: 134165162 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 60734760 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 60734760 0x10C5A3: trie_add (trie.c:110)
   n1: 60734760 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 60734760 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 60734760 0x111AD0: main_tests (main.c:95)
      n0: 60734760 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=21
#-----------
time=8067385037
mem_heap_B=610620291
mem_heap_extra_B=144399069
mem_stacks_B=752
heap_tree=detailed
n6: 610620291 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 239316320 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 239316320 0x10C5A3: trie_add (trie.c:110)
   n1: 239316320 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 239316320 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 239316320 0x111AD0: main_tests (main.c:95)
      n0: 239316320 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 139919166 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 139919166 0x10C5A3: trie_add (trie.c:110)
   n1: 139919166 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 139919166 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 139919166 0x111AD0: main_tests (main.c:95)
      n0: 139919166 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 63344240 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 63344240 0x10C5A3: trie_add (trie.c:110)
   n1: 63344240 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 63344240 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 63344240 0x111AD0: main_tests (main.c:95)
      n0: 63344240 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=22
#-----------
time=8326459767
mem_heap_B=633486285
mem_heap_extra_B=152190099
mem_stacks_B=752
heap_tree=detailed
n6: 633486285 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 253745360 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 253745360 0x10C5A3: trie_add (trie.c:110)
   n1: 253745360 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 253745360 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 253745360 0x111AD0: main_tests (main.c:95)
      n0: 253745360 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 145729080 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 145729080 0x10C5A3: trie_add (trie.c:110)
   n1: 145729080 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 145729080 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 145729080 0x111AD0: main_tests (main.c:95)
      n0: 145729080 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 65971280 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 65971280 0x10C5A3: trie_add (trie.c:110)
   n1: 65971280 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 65971280 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 65971280 0x111AD0: main_tests (main.c:95)
      n0: 65971280 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=23
#-----------
time=8664426123
mem_heap_B=663364139
mem_heap_extra_B=162389901
mem_stacks_B=752
heap_tree=peak
n6: 663364139 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 272719240 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 272719240 0x10C5A3: trie_add (trie.c:110)
   n1: 272719240 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 272719240 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 272719240 0x111AD0: main_tests (main.c:95)
      n0: 272719240 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 153236574 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 153236574 0x10C5A3: trie_add (trie.c:110)
   n1: 153236574 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 153236574 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 153236574 0x111AD0: main_tests (main.c:95)
      n0: 153236574 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 69367760 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 69367760 0x10C5A3: trie_add (trie.c:110)
   n1: 69367760 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 69367760 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 69367760 0x111AD0: main_tests (main.c:95)
      n0: 69367760 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=24
#-----------
time=9071998593
mem_heap_B=666774354
mem_heap_extra_B=163554966
mem_stacks_B=576
heap_tree=detailed
n6: 666774354 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 274892760 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 274892760 0x10C5A3: trie_add (trie.c:110)
   n1: 274892760 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 274892760 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 274892760 0x111AD0: main_tests (main.c:95)
      n0: 274892760 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 154089149 0x10C5A3: trie_add (trie.c:110)
   n1: 154089149 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 154089149 0x111AD0: main_tests (main.c:95)
      n0: 154089149 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 69751880 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 69751880 0x10C5A3: trie_add (trie.c:110)
   n1: 69751880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 69751880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 69751880 0x111AD0: main_tests (main.c:95)
      n0: 69751880 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=25
#-----------
time=9497758238
mem_heap_B=666774354
mem_heap_extra_B=163554966
mem_stacks_B=608
heap_tree=detailed
n6: 666774354 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 274892760 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 274892760 0x10C5A3: trie_add (trie.c:110)
   n1: 274892760 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 274892760 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 274892760 0x111AD0: main_tests (main.c:95)
      n0: 274892760 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 154089149 0x10C5A3: trie_add (trie.c:110)
   n1: 154089149 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 154089149 0x111AD0: main_tests (main.c:95)
      n0: 154089149 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 69751880 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 69751880 0x10C5A3: trie_add (trie.c:110)
   n1: 69751880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 69751880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 69751880 0x111AD0: main_tests (main.c:95)
      n0: 69751880 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=26
#-----------
time=9720351405
mem_heap_B=666774354
mem_heap_extra_B=163554966
mem_stacks_B=680
heap_tree=detailed
n6: 666774354 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 274892760 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 274892760 0x10C5A3: trie_add (trie.c:110)
   n1: 274892760 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 274892760 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 274892760 0x111AD0: main_tests (main.c:95)
      n0: 274892760 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 154089149 0x10C5A3: trie_add (trie.c:110)
   n1: 154089149 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 154089149 0x111AD0: main_tests (main.c:95)
      n0: 154089149 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 69751880 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 69751880 0x10C5A3: trie_add (trie.c:110)
   n1: 69751880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 69751880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 69751880 0x111AD0: main_tests (main.c:95)
      n0: 69751880 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=27
#-----------
time=9950395469
mem_heap_B=666774354
mem_heap_extra_B=163554966
mem_stacks_B=672
heap_tree=detailed
n6: 666774354 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 274892760 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 274892760 0x10C5A3: trie_add (trie.c:110)
   n1: 274892760 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 274892760 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 274892760 0x111AD0: main_tests (main.c:95)
      n0: 274892760 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 154089149 0x10C5A3: trie_add (trie.c:110)
   n1: 154089149 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 154089149 0x111AD0: main_tests (main.c:95)
      n0: 154089149 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 69751880 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 69751880 0x10C5A3: trie_add (trie.c:110)
   n1: 69751880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 69751880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 69751880 0x111AD0: main_tests (main.c:95)
      n0: 69751880 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=28
#-----------
time=10187931494
mem_heap_B=666774354
mem_heap_extra_B=163554966
mem_stacks_B=680
heap_tree=detailed
n6: 666774354 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 274892760 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 274892760 0x10C5A3: trie_add (trie.c:110)
   n1: 274892760 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 274892760 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 274892760 0x111AD0: main_tests (main.c:95)
      n0: 274892760 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 154089149 0x10C5A3: trie_add (trie.c:110)
   n1: 154089149 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 154089149 0x111AD0: main_tests (main.c:95)
      n0: 154089149 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 69751880 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 69751880 0x10C5A3: trie_add (trie.c:110)
   n1: 69751880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 69751880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 69751880 0x111AD0: main_tests (main.c:95)
      n0: 69751880 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=29
#-----------
time=10432474584
mem_heap_B=666774354
mem_heap_extra_B=163554966
mem_stacks_B=608
heap_tree=detailed
n6: 666774354 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 274892760 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 274892760 0x10C5A3: trie_add (trie.c:110)
   n1: 274892760 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 274892760 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 274892760 0x111AD0: main_tests (main.c:95)
      n0: 274892760 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 154089149 0x10C5A3: trie_add (trie.c:110)
   n1: 154089149 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 154089149 0x111AD0: main_tests (main.c:95)
      n0: 154089149 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 69751880 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 69751880 0x10C5A3: trie_add (trie.c:110)
   n1: 69751880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 69751880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 69751880 0x111AD0: main_tests (main.c:95)
      n0: 69751880 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=30
#-----------
time=10677473865
mem_heap_B=666774354
mem_heap_extra_B=163554966
mem_stacks_B=576
heap_tree=detailed
n6: 666774354 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 274892760 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 274892760 0x10C5A3: trie_add (trie.c:110)
   n1: 274892760 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 274892760 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 274892760 0x111AD0: main_tests (main.c:95)
      n0: 274892760 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 154089149 0x10C5A3: trie_add (trie.c:110)
   n1: 154089149 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 154089149 0x111AD0: main_tests (main.c:95)
      n0: 154089149 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 69751880 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 69751880 0x10C5A3: trie_add (trie.c:110)
   n1: 69751880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 69751880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 69751880 0x111AD0: main_tests (main.c:95)
      n0: 69751880 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=31
#-----------
time=10929448085
mem_heap_B=666774354
mem_heap_extra_B=163554966
mem_stacks_B=576
heap_tree=detailed
n6: 666774354 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 274892760 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 274892760 0x10C5A3: trie_add (trie.c:110)
   n1: 274892760 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 274892760 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 274892760 0x111AD0: main_tests (main.c:95)
      n0: 274892760 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 154089149 0x10C5A3: trie_add (trie.c:110)
   n1: 154089149 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 154089149 0x111AD0: main_tests (main.c:95)
      n0: 154089149 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 69751880 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 69751880 0x10C5A3: trie_add (trie.c:110)
   n1: 69751880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 69751880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 69751880 0x111AD0: main_tests (main.c:95)
      n0: 69751880 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=32
#-----------
time=11188483129
mem_heap_B=666774354
mem_heap_extra_B=163554966
mem_stacks_B=576
heap_tree=detailed
n6: 666774354 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 274892760 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 274892760 0x10C5A3: trie_add (trie.c:110)
   n1: 274892760 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 274892760 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 274892760 0x111AD0: main_tests (main.c:95)
      n0: 274892760 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 154089149 0x10C5A3: trie_add (trie.c:110)
   n1: 154089149 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 154089149 0x111AD0: main_tests (main.c:95)
      n0: 154089149 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 69751880 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 69751880 0x10C5A3: trie_add (trie.c:110)
   n1: 69751880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 69751880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 69751880 0x111AD0: main_tests (main.c:95)
      n0: 69751880 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=33
#-----------
time=11452640467
mem_heap_B=666774354
mem_heap_extra_B=163554966
mem_stacks_B=680
heap_tree=detailed
n6: 666774354 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 274892760 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 274892760 0x10C5A3: trie_add (trie.c:110)
   n1: 274892760 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 274892760 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 274892760 0x111AD0: main_tests (main.c:95)
      n0: 274892760 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 154089149 0x10C5A3: trie_add (trie.c:110)
   n1: 154089149 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 154089149 0x111AD0: main_tests (main.c:95)
      n0: 154089149 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 69751880 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 69751880 0x10C5A3: trie_add (trie.c:110)
   n1: 69751880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 69751880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 69751880 0x111AD0: main_tests (main.c:95)
      n0: 69751880 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=34
#-----------
time=11734084597
mem_heap_B=666774354
mem_heap_extra_B=163554966
mem_stacks_B=608
heap_tree=detailed
n6: 666774354 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 274892760 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 274892760 0x10C5A3: trie_add (trie.c:110)
   n1: 274892760 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 274892760 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 274892760 0x111AD0: main_tests (main.c:95)
      n0: 274892760 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 154089149 0x10C5A3: trie_add (trie.c:110)
   n1: 154089149 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 154089149 0x111AD0: main_tests (main.c:95)
      n0: 154089149 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 69751880 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 69751880 0x10C5A3: trie_add (trie.c:110)
   n1: 69751880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 69751880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 69751880 0x111AD0: main_tests (main.c:95)
      n0: 69751880 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=35
#-----------
time=12015982290
mem_heap_B=666774354
mem_heap_extra_B=163554966
mem_stacks_B=672
heap_tree=detailed
n6: 666774354 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 274892760 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 274892760 0x10C5A3: trie_add (trie.c:110)
   n1: 274892760 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 274892760 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 274892760 0x111AD0: main_tests (main.c:95)
      n0: 274892760 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 154089149 0x10C5A3: trie_add (trie.c:110)
   n1: 154089149 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 154089149 0x111AD0: main_tests (main.c:95)
      n0: 154089149 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 69751880 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 69751880 0x10C5A3: trie_add (trie.c:110)
   n1: 69751880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 69751880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 69751880 0x111AD0: main_tests (main.c:95)
      n0: 69751880 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=36
#-----------
time=12306787975
mem_heap_B=666774354
mem_heap_extra_B=163554966
mem_stacks_B=680
heap_tree=detailed
n6: 666774354 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 274892760 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 274892760 0x10C5A3: trie_add (trie.c:110)
   n1: 274892760 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 274892760 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 274892760 0x111AD0: main_tests (main.c:95)
      n0: 274892760 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 154089149 0x10C5A3: trie_add (trie.c:110)
   n1: 154089149 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 154089149 0x111AD0: main_tests (main.c:95)
      n0: 154089149 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 69751880 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 69751880 0x10C5A3: trie_add (trie.c:110)
   n1: 69751880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 69751880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 69751880 0x111AD0: main_tests (main.c:95)
      n0: 69751880 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=37
#-----------
time=12609203902
mem_heap_B=666774354
mem_heap_extra_B=163554966
mem_stacks_B=608
heap_tree=detailed
n6: 666774354 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 274892760 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 274892760 0x10C5A3: trie_add (trie.c:110)
   n1: 274892760 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 274892760 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 274892760 0x111AD0: main_tests (main.c:95)
      n0: 274892760 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 154089149 0x10C5A3: trie_add (trie.c:110)
   n1: 154089149 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 154089149 0x111AD0: main_tests (main.c:95)
      n0: 154089149 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 69751880 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 69751880 0x10C5A3: trie_add (trie.c:110)
   n1: 69751880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 69751880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 69751880 0x111AD0: main_tests (main.c:95)
      n0: 69751880 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=38
#-----------
time=12916434743
mem_heap_B=666774354
mem_heap_extra_B=163554966
mem_stacks_B=672
heap_tree=detailed
n6: 666774354 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 274892760 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 274892760 0x10C5A3: trie_add (trie.c:110)
   n1: 274892760 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 274892760 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 274892760 0x111AD0: main_tests (main.c:95)
      n0: 274892760 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 154089149 0x10C5A3: trie_add (trie.c:110)
   n1: 154089149 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 154089149 0x111AD0: main_tests (main.c:95)
      n0: 154089149 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 69751880 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 69751880 0x10C5A3: trie_add (trie.c:110)
   n1: 69751880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 69751880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 69751880 0x111AD0: main_tests (main.c:95)
      n0: 69751880 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=39
#-----------
time=13254395502
mem_heap_B=666774354
mem_heap_extra_B=163554966
mem_stacks_B=608
heap_tree=detailed
n6: 666774354 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 274892760 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 274892760 0x10C5A3: trie_add (trie.c:110)
   n1: 274892760 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 274892760 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 274892760 0x111AD0: main_tests (main.c:95)
      n0: 274892760 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 154089149 0x10C5A3: trie_add (trie.c:110)
   n1: 154089149 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 154089149 0x111AD0: main_tests (main.c:95)
      n0: 154089149 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 69751880 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 69751880 0x10C5A3: trie_add (trie.c:110)
   n1: 69751880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 69751880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 69751880 0x111AD0: main_tests (main.c:95)
      n0: 69751880 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=40
#-----------
time=13606147831
mem_heap_B=666774354
mem_heap_extra_B=163554966
mem_stacks_B=608
heap_tree=detailed
n6: 666774354 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 274892760 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 274892760 0x10C5A3: trie_add (trie.c:110)
   n1: 274892760 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 274892760 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 274892760 0x111AD0: main_tests (main.c:95)
      n0: 274892760 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 154089149 0x10C5A3: trie_add (trie.c:110)
   n1: 154089149 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 154089149 0x111AD0: main_tests (main.c:95)
      n0: 154089149 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 69751880 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 69751880 0x10C5A3: trie_add (trie.c:110)
   n1: 69751880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 69751880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 69751880 0x111AD0: main_tests (main.c:95)
      n0: 69751880 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1040 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=41
#-----------
time=13981853250
mem_heap_B=652308648
mem_heap_extra_B=159548560
mem_stacks_B=6984
heap_tree=detailed
n6: 652308648 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 271091080 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 271091080 0x10C5A3: trie_add (trie.c:110)
   n1: 271091080 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 271091080 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 271091080 0x111AD0: main_tests (main.c:95)
      n0: 271091080 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 146458803 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 146458803 0x10C5A3: trie_add (trie.c:110)
   n1: 146458803 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 146458803 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 146458803 0x111AD0: main_tests (main.c:95)
      n0: 146458803 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 66298440 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 66298440 0x10C5A3: trie_add (trie.c:110)
   n1: 66298440 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 66298440 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 66298440 0x111AD0: main_tests (main.c:95)
      n0: 66298440 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 420800 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=42
#-----------
time=14362673944
mem_heap_B=634945349
mem_heap_extra_B=154618699
mem_stacks_B=4104
heap_tree=detailed
n6: 634945349 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 265867120 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 265867120 0x10C5A3: trie_add (trie.c:110)
   n1: 265867120 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 265867120 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 265867120 0x111AD0: main_tests (main.c:95)
      n0: 265867120 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 137818544 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 137818544 0x10C5A3: trie_add (trie.c:110)
   n1: 137818544 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 137818544 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 137818544 0x111AD0: main_tests (main.c:95)
      n0: 137818544 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 62388080 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 62388080 0x10C5A3: trie_add (trie.c:110)
   n1: 62388080 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 62388080 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 62388080 0x111AD0: main_tests (main.c:95)
      n0: 62388080 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 832080 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=43
#-----------
time=14762449497
mem_heap_B=615831690
mem_heap_extra_B=149071014
mem_stacks_B=1128
heap_tree=detailed
n6: 615831690 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 259446480 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 259446480 0x10C5A3: trie_add (trie.c:110)
   n1: 259446480 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 259446480 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 259446480 0x111AD0: main_tests (main.c:95)
      n0: 259446480 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 128824725 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 128824725 0x10C5A3: trie_add (trie.c:110)
   n1: 128824725 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 128824725 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 128824725 0x111AD0: main_tests (main.c:95)
      n0: 128824725 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 58317840 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 58317840 0x10C5A3: trie_add (trie.c:110)
   n1: 58317840 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 58317840 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 58317840 0x111AD0: main_tests (main.c:95)
      n0: 58317840 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1203120 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=44
#-----------
time=15170020957
mem_heap_B=595319296
mem_heap_extra_B=142995888
mem_stacks_B=6616
heap_tree=detailed
n6: 595319296 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 251880640 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 251880640 0x10C5A3: trie_add (trie.c:110)
   n1: 251880640 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 251880640 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 251880640 0x111AD0: main_tests (main.c:95)
      n0: 251880640 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 119694651 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 119694651 0x10C5A3: trie_add (trie.c:110)
   n1: 119694651 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 119694651 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 119694651 0x111AD0: main_tests (main.c:95)
      n0: 119694651 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 54186240 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 54186240 0x10C5A3: trie_add (trie.c:110)
   n1: 54186240 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 54186240 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 54186240 0x111AD0: main_tests (main.c:95)
      n0: 54186240 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1518240 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=45
#-----------
time=15595778017
mem_heap_B=572730455
mem_heap_extra_B=136173633
mem_stacks_B=2008
heap_tree=detailed
n6: 572730455 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 242826920 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 242826920 0x10C5A3: trie_add (trie.c:110)
   n1: 242826920 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 242826920 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 242826920 0x111AD0: main_tests (main.c:95)
      n0: 242826920 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 110206290 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 110206290 0x10C5A3: trie_add (trie.c:110)
   n1: 110206290 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 110206290 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 110206290 0x111AD0: main_tests (main.c:95)
      n0: 110206290 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 49891800 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 49891800 0x10C5A3: trie_add (trie.c:110)
   n1: 49891800 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 49891800 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 49891800 0x111AD0: main_tests (main.c:95)
      n0: 49891800 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1765920 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=46
#-----------
time=16021573248
mem_heap_B=548910234
mem_heap_extra_B=128847990
mem_stacks_B=5448
heap_tree=detailed
n6: 548910234 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 232537160 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 232537160 0x10C5A3: trie_add (trie.c:110)
   n1: 232537160 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 232537160 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 232537160 0x111AD0: main_tests (main.c:95)
      n0: 232537160 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 100763909 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 100763909 0x10C5A3: trie_add (trie.c:110)
   n1: 100763909 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 100763909 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 100763909 0x111AD0: main_tests (main.c:95)
      n0: 100763909 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 45618960 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 45618960 0x10C5A3: trie_add (trie.c:110)
   n1: 45618960 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 45618960 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 45618960 0x111AD0: main_tests (main.c:95)
      n0: 45618960 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 1950680 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=47
#-----------
time=16462999223
mem_heap_B=522949912
mem_heap_extra_B=120737184
mem_stacks_B=5736
heap_tree=detailed
n6: 522949912 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 220618400 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 220618400 0x10C5A3: trie_add (trie.c:110)
   n1: 220618400 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 220618400 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 220618400 0x111AD0: main_tests (main.c:95)
      n0: 220618400 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 91015747 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 91015747 0x10C5A3: trie_add (trie.c:110)
   n1: 91015747 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 91015747 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 91015747 0x111AD0: main_tests (main.c:95)
      n0: 91015747 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 41203320 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 41203320 0x10C5A3: trie_add (trie.c:110)
   n1: 41203320 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 41203320 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 41203320 0x111AD0: main_tests (main.c:95)
      n0: 41203320 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 2072920 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=48
#-----------
time=16912847890
mem_heap_B=495065157
mem_heap_extra_B=111891363
mem_stacks_B=9000
heap_tree=detailed
n6: 495065157 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 207059320 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 207059320 0x10C5A3: trie_add (trie.c:110)
   n1: 207059320 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 207059320 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 207059320 0x111AD0: main_tests (main.c:95)
      n0: 207059320 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 81120152 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 81120152 0x10C5A3: trie_add (trie.c:110)
   n1: 81120152 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 81120152 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 81120152 0x111AD0: main_tests (main.c:95)
      n0: 81120152 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 36723840 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 36723840 0x10C5A3: trie_add (trie.c:110)
   n1: 36723840 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 36723840 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 36723840 0x111AD0: main_tests (main.c:95)
      n0: 36723840 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 2122320 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=49
#-----------
time=17337761974
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7952
heap_tree=detailed
n6: 467364008 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 192926880 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 192926880 0x10C5A3: trie_add (trie.c:110)
   n1: 192926880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 192926880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 192926880 0x111AD0: main_tests (main.c:95)
      n0: 192926880 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 71799267 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 71799267 0x10C5A3: trie_add (trie.c:110)
   n1: 71799267 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 71799267 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 71799267 0x111AD0: main_tests (main.c:95)
      n0: 71799267 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 32507920 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 32507920 0x10C5A3: trie_add (trie.c:110)
   n1: 32507920 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 32507920 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 32507920 0x111AD0: main_tests (main.c:95)
      n0: 32507920 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 2090416 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=50
#-----------
time=17337762037
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7912
heap_tree=empty
#-----------
snapshot=51
#-----------
time=17337762091
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7912
heap_tree=empty
#-----------
snapshot=52
#-----------
time=17337762145
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7912
heap_tree=empty
#-----------
snapshot=53
#-----------
time=17337762205
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7880
heap_tree=empty
#-----------
snapshot=54
#-----------
time=17337762262
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7872
heap_tree=empty
#-----------
snapshot=55
#-----------
time=17337762387
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7920
heap_tree=empty
#-----------
snapshot=56
#-----------
time=17337762446
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7880
heap_tree=empty
#-----------
snapshot=57
#-----------
time=17337762509
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7880
heap_tree=empty
#-----------
snapshot=58
#-----------
time=17337762572
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7880
heap_tree=empty
#-----------
snapshot=59
#-----------
time=17337762635
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7880
heap_tree=detailed
n6: 467364008 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 192926880 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 192926880 0x10C5A3: trie_add (trie.c:110)
   n1: 192926880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 192926880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 192926880 0x111AD0: main_tests (main.c:95)
      n0: 192926880 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 71799267 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 71799267 0x10C5A3: trie_add (trie.c:110)
   n1: 71799267 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 71799267 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 71799267 0x111AD0: main_tests (main.c:95)
      n0: 71799267 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 32507920 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 32507920 0x10C5A3: trie_add (trie.c:110)
   n1: 32507920 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 32507920 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 32507920 0x111AD0: main_tests (main.c:95)
      n0: 32507920 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 2090416 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=60
#-----------
time=17337762698
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7880
heap_tree=empty
#-----------
snapshot=61
#-----------
time=17337762761
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7880
heap_tree=empty
#-----------
snapshot=62
#-----------
time=17337762824
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7880
heap_tree=empty
#-----------
snapshot=63
#-----------
time=17337762887
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7880
heap_tree=empty
#-----------
snapshot=64
#-----------
time=17337762950
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7880
heap_tree=empty
#-----------
snapshot=65
#-----------
time=17337763013
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7880
heap_tree=empty
#-----------
snapshot=66
#-----------
time=17337763076
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7880
heap_tree=empty
#-----------
snapshot=67
#-----------
time=17337763139
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7880
heap_tree=empty
#-----------
snapshot=68
#-----------
time=17337763202
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7880
heap_tree=empty
#-----------
snapshot=69
#-----------
time=17337763265
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7880
heap_tree=detailed
n6: 467364008 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 192926880 0x10B3D0: ternarytrie_add (ternarytrie.c:164)
  n2: 192926880 0x10C5A3: trie_add (trie.c:110)
   n1: 192926880 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 192926880 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 192926880 0x111AD0: main_tests (main.c:95)
      n0: 192926880 0x111B08: main (main.c:102)
   n0: 0 in 19 places, all below massif's threshold (1.00%)
 n1: 154089149 0x10C781: dataset_file_load (dataset.c:45)
  n1: 154089149 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 154089149 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 154089149 0x111AD0: main_tests (main.c:95)
     n0: 154089149 0x111B08: main (main.c:102)
 n1: 71799267 0x10B346: ternarytrie_add (ternarytrie.c:154)
  n2: 71799267 0x10C5A3: trie_add (trie.c:110)
   n1: 71799267 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 71799267 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 71799267 0x111AD0: main_tests (main.c:95)
      n0: 71799267 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 32507920 0x10B2F0: ternarytrie_add (ternarytrie.c:148)
  n2: 32507920 0x10C5A3: trie_add (trie.c:110)
   n1: 32507920 0x110A36: tests_trie_afbyrm (tests.c:413)
    n1: 32507920 0x10AE56: testutils_run_multiple (testutils.c:287)
     n1: 32507920 0x111AD0: main_tests (main.c:95)
      n0: 32507920 0x111B08: main (main.c:102)
   n0: 0 in 38 places, all below massif's threshold (1.00%)
 n1: 13950376 0x10C812: dataset_file_load (dataset.c:54)
  n1: 13950376 0x1109BF: tests_trie_afbyrm (tests.c:405)
   n1: 13950376 0x10AE56: testutils_run_multiple (testutils.c:287)
    n1: 13950376 0x111AD0: main_tests (main.c:95)
     n0: 13950376 0x111B08: main (main.c:102)
 n0: 2090416 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=70
#-----------
time=17337763328
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7880
heap_tree=empty
#-----------
snapshot=71
#-----------
time=17337763391
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7880
heap_tree=empty
#-----------
snapshot=72
#-----------
time=17337763454
mem_heap_B=467364008
mem_heap_extra_B=102985744
mem_stacks_B=7880
heap_tree=empty
