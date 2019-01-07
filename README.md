# Assembly Line
This project was created as part of BTP305 course at Seneca College. It simulates an assembly line in a manufacture where it would fill the orders as they come. It also includes an inventory tracking system.

# Building
This project uses the C++17 standard and can be compiled with both GCC and CLANG.

```bash
g++ -std=c++17 -Wall Inventory.cpp LineManger.cpp Task.cpp Utilities.cpp Item.cpp ms3.cpp
```

# Usage
The program takes the following parameters:
1. Inventory file
2. Inventory file
3. Customer orders
4. Assembly line

```bash
./a.out Inventory1.dat Inventory2.dat CustomerOrders.dat AssemblyLine.dat
```

# Demo
```
=======================
=   Tasks (summary)   =
=======================
CPU          [123456]
Memory       [654321]
GPU          [056789]
SSD          [987654]
Power Supply [147852]

=======================
=    Tasks (full)     =
=======================
CPU          [123456] Quantity: 5            Description: Central Processing Unit
Memory       [654321] Quantity: 10           Description: Basic Flash Memory
GPU          [056789] Quantity: 7            Description: General Porcessing Unit
SSD          [987654] Quantity: 5            Description: Solid State Drive
Power Supply [147852] Quantity: 20           Description: Basic AC Power Supply

=======================
=  Manual Validation  =
=======================
getName(): CPU
getSerialNumber(): 123456
getSerialNumber(): 123457
getQuantity(): 5
getQuantity(): 4

=======================
=        Orders       =
=======================
Elliott C. - Gaming PC
[000000] CPU              - MISSING
[000000] Memory           - MISSING
[000000] GPU              - MISSING
[000000] GPU              - MISSING
[000000] GPU              - MISSING
[000000] SSD              - MISSING
[000000] Power Supply     - MISSING
Chris S. - Laptop
[000000] CPU              - MISSING
[000000] Memory           - MISSING
[000000] SSD              - MISSING
[000000] Power Supply     - MISSING
Mary-Lynn M. - Desktop PC
[000000] CPU              - MISSING
[000000] Memory           - MISSING
[000000] Power Supply     - MISSING
Chris T. - Micro Controller
[000000] GPU              - MISSING
[000000] GPU              - MISSING
[000000] Power Supply     - MISSING
[000000] SSD              - MISSING

=======================
=   Validate Tasks    =
=======================
CPU --> GPU
Memory --> SSD
GPU --> Memory
SSD --> END OF LINE
Power Supply --> CPU

=======================
=   Filling Orders    =
=======================
Filled Elliott C., Gaming PC[Power Supply]
Filled Elliott C., Gaming PC[CPU]
Filled Chris S., Laptop[Power Supply]
Filled Chris S., Laptop[CPU]
Filled Elliott C., Gaming PC[GPU]
Filled Elliott C., Gaming PC[GPU]
Filled Elliott C., Gaming PC[GPU]
Filled Mary-Lynn M., Desktop PC[Power Supply]
Filled Mary-Lynn M., Desktop PC[CPU]
Filled Elliott C., Gaming PC[Memory]
Filled Chris T., Micro Controller[Power Supply]
Filled Chris S., Laptop[Memory]
Filled Elliott C., Gaming PC[SSD]
Filled Mary-Lynn M., Desktop PC[Memory]
Filled Chris T., Micro Controller[GPU]
Filled Chris T., Micro Controller[GPU]
Filled Chris S., Laptop[SSD]
Filled Chris T., Micro Controller[SSD]

=======================
=   Completed Orders  =
=======================
Elliott C. - Gaming PC
[123458] CPU              - FILLED
[654321] Memory           - FILLED
[056789] GPU              - FILLED
[056790] GPU              - FILLED
[056791] GPU              - FILLED
[987654] SSD              - FILLED
[147852] Power Supply     - FILLED
Chris S. - Laptop
[123459] CPU              - FILLED
[654322] Memory           - FILLED
[987655] SSD              - FILLED
[147853] Power Supply     - FILLED
Mary-Lynn M. - Desktop PC
[123460] CPU              - FILLED
[654323] Memory           - FILLED
[147854] Power Supply     - FILLED
Chris T. - Micro Controller
[056792] GPU              - FILLED
[056793] GPU              - FILLED
[147855] Power Supply     - FILLED
[987656] SSD              - FILLED

=======================
=  Inventory (full)   =
=======================
CPU          [123461] Quantity: 1            Description: Central Processing Unit
Memory       [654324] Quantity: 7            Description: Basic Flash Memory
GPU          [056794] Quantity: 2            Description: General Porcessing Unit
SSD          [987657] Quantity: 2            Description: Solid State Drive
Power Supply [147856] Quantity: 16           Description: Basic AC Power Supply
```