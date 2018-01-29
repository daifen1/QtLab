#include <QApplication>
#include <QPushButton>
#include <QStateMachine>
#include <QSignalTransition>
#include <QPropertyAnimation>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget *w=new QWidget;
    w->resize(240,320);                                 //������

    QPushButton *button = new QPushButton("shuoGG",w);   //����ť

    QStateMachine *machine = new QStateMachine;     //�½�״̬��,�൱��״̬������
    QState *state1 = new QState(machine);           //�½�״̬1��������������;״̬����״̬������
    state1->assignProperty(button,"geometry",QRect(0,0,80,30));    //״̬1��button��geomertry����1
    machine->setInitialState(state1);                //state1��Ϊ��ʼ��״̬
    QState *state2 = new QState(machine);           //�½�����һ��״̬2
    state2->assignProperty(button,"geometry",QRect(w->width()-30,w->height()-80,30,80));//״̬2��button��geomertry����2

    QFont font = QFont("Airl", 12);
    state2->assignProperty(button,"font",font);     //״̬2����.1��״̬�����ж�������:�����ӵ�״̬����:��������+��������

    QPropertyAnimation *ani=new QPropertyAnimation(button,"geometry");
    ani->setDuration(2000);
    ani->setEasingCurve(QEasingCurve::OutBounce);   //����Ч��������
//addTransition()�������ص���һ��QSignalTransition�͵�ָ��
    QSignalTransition *transition1=state1->addTransition(button,SIGNAL(clicked()),state2);//���������ź�
    transition1->addAnimation(ani);   //ת��1==(button���=(state1->state2))  //��ת��1��Ӷ���ani
    QSignalTransition *transition2=state2->addTransition(button,SIGNAL(clicked()),state1);
    transition2->addAnimation(ani);   //ת��2==(button���=(state2->state1))  //��ת��2��Ӷ���ani
    machine->start();                           //����״̬��
    w->show();
    return app.exec();
}
