# Sora

## Solution

This is a pretty run of the mill keygen.
I would not recommend cracking this by hand however.

There is a great tool called angr, it can make your life so much better :)

Thanks to Sky on discord for pointing it out.

```python

import angr
import sys
from claripy import *



binary = "sora"
project = angr.Project(binary, load_options={'main_opts': {'base_addr': 0x0}})

input_key = BVS('x', 0x1e * 8)


initial_state = project.factory.entry_state(stdin=input_key)


# ensure input is within printable range
for c in input_key.chop(8):
    initial_state.solver.add(initial_state.solver.And(c <= '~', c >= ' '))

simulation = project.factory.simgr(initial_state)

simulation.explore(find=0x13b4)

if simulation.found:
    solution_state = simulation.found[0]
    print(str(solution_state.solver.eval(input_key, cast_to=bytes)))


else:
    raise Exception('Could not find the solution')


```
