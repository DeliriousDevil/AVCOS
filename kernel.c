#include "init.h"
#include "memory_manager.h"
#include "scheduler.h" 
#include "driver_hdmi.h" 
#include "vfs.h"
#include "network_init.h"
#include "driver_usb_wifi.h"

void kernel_main() {
    init_serial();
    init_hdmi();
    init_memory();
    init_idt();
    init_gdt();
    init_tss();
    init_scheduler();
    init_vfs();
    init_network();
    init_usb_wifi();
    
    hdmi_write("kernel initialized. Handing over to the scheduler...\n");
    start_scheduler();
}