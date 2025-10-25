#include <gst/gst.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    gst_init(&argc, &argv);
    printf("GStreamer initialized!\n");
    return 0;
}