

//PSA.cpp
#include "PSA.h"

//������ҵ��Ϣ
void InputPCB(std::vector<PCB> &PCBList)
{
    do {
        PCB temp;
        std::cout << "�����ʶ��: ";
        std::cin >> temp.ID;
        std::cout << "�������ȼ�: ";
        std::cin >> temp.Level;
        std::cout << "���뵽��ʱ��: ";
        std::cin >> temp.ComeTime;
        std::cout << "�������ʱ��: ";
        std::cin >> temp.ServerTime;
        PCBList.push_back(temp);

        std::cout << "�������룿Y/N: ";
        char ans;
        std::cin >> ans;
        if ('Y' == ans || 'y' == ans)
            continue;
        else
            break;
    } while (true);
}

//PSA�㷨
void PSA(std::vector<PCB> &PCBList)
{
    std::sort(PCBList.begin(), PCBList.end(), CmpByComeTime);		//������ʱ������

    //ͬʱ����İ����ȼ��������򣬾����������е���ҵ
    int i = 1;
    std::vector<PCB>::iterator it = PCBList.begin() + 1;
    while ((*it).ComeTime == (*(it - 1)).ComeTime)
    {
        ++i;
        ++it;
    }
    std::sort(PCBList.begin(), PCBList.begin() + i, CmpByLevel);

    int FinishTime = -1;
    for (it = PCBList.begin(); it < PCBList.end(); ++it)
    {
        if ((*it).ComeTime >= FinishTime)		//û����ҵ�������У�ȡ������ҵ����
            (*it).FinishTime = (*it).ComeTime + (*it).ServerTime;
        else									//����ҵ�������У��ȴ���ҵ��ϣ�����ҵ������
            (*it).FinishTime = FinishTime + (*it).ServerTime;
        (*it).TurnoverTime = (*it).FinishTime - (*it).ComeTime;
        (*it).WeightedTurnoverTime = (double)(*it).TurnoverTime / (*it).ServerTime;
        FinishTime = (*it).FinishTime;

        //��һ����ҵ�����ڼ䣬�����������ҵ��������ǰ������ȼ���������
        i = 1;
        while ((it + i) < PCBList.end() && (*(it + i)).ComeTime <= FinishTime)
            ++i;
        std::sort(it + 1, it + i, CmpByLevel);
    }

    std::sort(PCBList.begin(), PCBList.end(), CmpByComeTime);		//�������У�������ʾ���
}

//��ʾ���
void show(std::vector<PCB> &PCBList)
{
    int SumTurnoverTime = 0;
    double SumWeightedTurnoverTime = 0;

    std::cout.setf(std::ios::left);

    std::cout << std::setw(20) << "��ʶ��";
    for (std::vector<PCB>::iterator it = PCBList.begin(); it < PCBList.end(); ++it)
        std::cout << std::setw(5) << (*it).ID;
    std::cout << std::endl;

    std::cout << std::setw(20) << "���ȼ�";
    for (std::vector<PCB>::iterator it = PCBList.begin(); it < PCBList.end(); ++it)
        std::cout << std::setw(5) << (*it).Level;
    std::cout << std::endl;

    std::cout << std::setw(20) << "����ʱ��";
    for (std::vector<PCB>::iterator it = PCBList.begin(); it < PCBList.end(); ++it)
        std::cout << std::setw(5) << (*it).ComeTime;
    std::cout << std::endl;

    std::cout << std::setw(20) << "����ʱ��";
    for (std::vector<PCB>::iterator it = PCBList.begin(); it < PCBList.end(); ++it)
        std::cout << std::setw(5) << (*it).ServerTime;
    std::cout << std::endl;

    std::cout << std::setw(20) << "���ʱ��";
    for (std::vector<PCB>::iterator it = PCBList.begin(); it < PCBList.end(); ++it)
        std::cout << std::setw(5) << (*it).FinishTime;
    std::cout << std::endl;

    std::cout << std::setw(20) << "��תʱ��";
    for (std::vector<PCB>::iterator it = PCBList.begin(); it < PCBList.end(); ++it)
    {
        std::cout << std::setw(5) << (*it).TurnoverTime;
        SumTurnoverTime += (*it).TurnoverTime;;
    }
    std::cout << std::endl;

    std::cout << std::setw(20) << "��Ȩ��תʱ��";
    for (std::vector<PCB>::iterator it = PCBList.begin(); it < PCBList.end(); ++it)
    {
        std::cout << std::setw(5) << (*it).WeightedTurnoverTime;
        SumWeightedTurnoverTime += (*it).WeightedTurnoverTime;;
    }
    std::cout << std::endl;

    std::cout << "ƽ����תʱ��: " << (double)SumTurnoverTime / PCBList.size() << std::endl;
    std::cout << "ƽ����Ȩ��תʱ��: " << SumWeightedTurnoverTime / PCBList.size() << std::endl;
}

//�ȽϺ�������ComeTime��������
bool CmpByComeTime(const PCB &p1, const PCB &p2)
{
    return p1.ComeTime < p2.ComeTime;
}

//�ȽϺ�������Level��������
bool CmpByLevel(const PCB &p1, const PCB &p2)
{
    return p1.Level > p2.Level;
}
