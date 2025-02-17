// Copyright 2023 Muhammad Hayat
#include <assert.h>
#include <stdio.h>
#include "/home/hayat/C_programming/su21-lab-starter/lab01/exercise4/ll_cycle.h"
int main(void) {
    // DO NOT EDIT ANY OF THE FOLLOWING CODE
    printf("Running tests...\n\n");

  int i;
  node nodes[25];  // enough to run our tests
    for (i = 0; i < sizeof(nodes)/sizeof(node); i++) {
        nodes[i].next = 0;
        nodes[i].value = 0;
    }

    nodes[0].next = &nodes[1];
    nodes[1].next = &nodes[2];
    nodes[2].next = &nodes[3];
    printf("Checking first list for cycles. There should be none, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&nodes[0]) ? "a" : "no");
    assert(!ll_has_cycle(&nodes[0]));

    nodes[4].next = &nodes[5];
    nodes[5].next = &nodes[6];
    nodes[6].next = &nodes[7];
    nodes[7].next = &nodes[8];
    nodes[8].next = &nodes[9];
    nodes[9].next = &nodes[10];
    nodes[10].next = &nodes[4];
    printf("Checking second list for cycles. There should be a cycle, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&nodes[4]) ? "a" : "no");
    assert(ll_has_cycle(&nodes[4]));

    nodes[11].next = &nodes[12];
    nodes[12].next = &nodes[13];
    nodes[13].next = &nodes[14];
    nodes[14].next = &nodes[15];
    nodes[15].next = &nodes[16];
    nodes[16].next = &nodes[17];
    nodes[17].next = &nodes[14];
    printf("Checking third list for cycles. There should be a cycle, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&nodes[11]) ? "a" : "no");
    assert(ll_has_cycle(&nodes[11]));

    nodes[18].next = &nodes[18];
    printf("Checking fourth list for cycles. There should be a cycle, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&nodes[18]) ? "a" : "no");
    assert(ll_has_cycle(&nodes[18]));

    nodes[19].next = &nodes[20];
    nodes[20].next = &nodes[21];
    nodes[21].next = &nodes[22];
    nodes[22].next = &nodes[23];
    printf("Checking fifth list for cycles. There should be none, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&nodes[19]) ? "a" : "no");
    assert(!ll_has_cycle(&nodes[19]));

    printf("Checking length-zero list for cycles. There should be none, ll_has_cycle says it has %s cycle\n\n", ll_has_cycle(NULL) ? "a" : "no");
    assert(!ll_has_cycle(NULL));

    printf("Congrats, you passed all the test cases!\n");

    return 0;
}
