#include <stdio.h>
#include <math.h>

int main() {
  int memory[100];
  memory[0] = 1;
  memory[99] = 800;

  int pc = 0;
  int accml = 0;
  int instr = 0;
  
  while (1) {
    instr = memory[pc];
    pc++;

    int opcode = instr / 100;
    int address = instr % 100;

    switch (opcode) {
      case 0:
        scanf("%d", &memory[address]);
        break;
      
      case 1:
        accml = memory[address];
        break;

      case 2:
        accml += memory[address];
        break;

      case 3:
        if (accml < 0) {
          pc = address;
        }
        break;

      case 4:
        accml *= (int)pow(10, address / 10);
        accml /= (int)pow(10, address % 10);
        break;

      case 5:
        printf("%d\n", memory[address]);
        break;

      case 6:
        memory[address] = accml;
        break;

      case 7:
        accml -= memory[address];
        break;

      case 8:
        memory[99] = 800 + pc;
        pc = address;
        break;

      case 9:
        pc = address;
        return 0;
        break;
    }
  }   

  return 0;
}



