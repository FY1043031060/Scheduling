#include "PSA.h"
int main(int argc, char *argv[])
{
    std::vector<PCB> PCBList;

    //������ҵ��Ϣ
    InputPCB(PCBList);

    //PSA�㷨
    PSA(PCBList);

    //��ʾ���
    show(PCBList);

    return 0;
}
