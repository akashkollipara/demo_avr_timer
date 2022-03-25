#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <machine_call.h>
#include <resource.h>
#include <arch.h>
#include <hal/timer.h>

timer_port_t te;

void test()
{
	module_t *t;
	mret_t mres;
	arch_machine_call(fetch_dp, timer, 0x10, 0, &mres);
	if(mres.status != success)
	{
		printf("Error!\n");
		return;
	}
	t = (module_t *)mres.p;
	te.port_id = t->id;
	te.clk_id = t->clk_id;
	te.baddr = t->baddr;
	te.value = 7812;
	te.tmr_irq = t->interrupt[0].id;
	extern void temp();
	te.tmr_handler = temp;

	timer_setup(&te, 4, 5);
}

