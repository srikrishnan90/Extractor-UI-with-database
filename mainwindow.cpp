#include "mainwindow.h"
#include "ui_mainwindow.h"
int opt=0;
int from_edit=0;
static QString array[72]={""};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase sqdb = QSqlDatabase::addDatabase("QSQLITE");
    sqdb.setDatabaseName("/home/pi/git/ext.db");
    if(!sqdb.open())
    {
        //qDebug() << "Can't Connect to DB !";
        ui->label_4->setText("DB Error");
    }
    else
    {
        // qDebug() << "Connected Successfully to DB !";
        ui->label_4->setText("DB Successful");
    }
    ui->stackedWidget->setCurrentIndex(0);
    QSqlQuery query;
    //query.prepare("SELECT name FROM sqlite_master WHERE type='table'");
    query.prepare("SELECT name FROM DNA");
    query.exec();
    //int i=0;
    ui->listWidget->clear();
    while(query.next())
    {
        //qDebug()<<query.value(0).toString();
        //qDebug()<<i;
        //i++;
        //if(i!=0)
        ui->listWidget->addItem(query.value(0).toString());
        //i++;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_9_triggered(QAction *arg1)
{

}

void MainWindow::on_toolButton_9_clicked()
{
    auto home = new QWidget(this);
    auto stp=new QStackedWidget(this);
    stp->addWidget(home);
}

void MainWindow::on_toolButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->comboBox->clear();
    QSqlQuery query;
    //query.prepare("SELECT name FROM sqlite_master WHERE type='table'");
    query.prepare("SELECT name FROM DNA");
    query.exec();
    //int i=0;
    ui->comboBox->addItem("None");
    while(query.next())
    {
        //qDebug()<<query.value(0).toString();
        //qDebug()<<i;
        //i++;
        //if(i!=0)
        ui->comboBox->addItem(query.value(0).toString());
        //i++;
    }
}

void MainWindow::on_pushButton_110_clicked()
{
    opt=1;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->lineEdit_145->setText(ui->lineEdit->text());

}

void MainWindow::on_toolButton_25_clicked()
{
    QMessageBox msg;
    QString temp, name;

    temp=ui->comboBox->currentText();
    name=ui->lineEdit->text();

    if(temp!="None")
    {
        QSqlQuery query;
        query.prepare("select pname1,pname2,pname3,pname4,pname5,pname6,pname7 FROM DNA where name=:name");
        query.bindValue(":name",temp);
        query.exec();
        while(query.next())
        {
            ui->lineEdit_3->setText(query.value(0).toString());
            ui->lineEdit_14->setText(query.value(1).toString());
            ui->lineEdit_20->setText(query.value(2).toString());
            ui->lineEdit_26->setText(query.value(3).toString());
            ui->lineEdit_32->setText(query.value(4).toString());
            ui->lineEdit_38->setText(query.value(5).toString());
            ui->lineEdit_44->setText(query.value(6).toString());
        }

        query.prepare("select well1,well2,well3,well4,well5,well6,well7 FROM DNA where name=:name");
        query.bindValue(":name",temp);
        query.exec();
        while(query.next())
        {
            ui->comboBox_3->setCurrentIndex(query.value(0).toInt()-1);
            ui->comboBox_8->setCurrentIndex(query.value(1).toInt()-1);
            ui->comboBox_10->setCurrentIndex(query.value(2).toInt()-1);
            ui->comboBox_12->setCurrentIndex(query.value(3).toInt()-1);
            ui->comboBox_14->setCurrentIndex(query.value(4).toInt()-1);
            ui->comboBox_16->setCurrentIndex(query.value(5).toInt()-1);
            ui->comboBox_18->setCurrentIndex(query.value(6).toInt()-1);
        }

        query.prepare("select wait1,wait2,wait3,wait4,wait5,wait6,wait7 FROM DNA where name=:name");
        query.bindValue(":name",temp);
        query.exec();
        while(query.next())
        {
            ui->lineEdit_4->setText(query.value(0).toString());
            ui->lineEdit_12->setText(query.value(1).toString());
            ui->lineEdit_18->setText(query.value(2).toString());
            ui->lineEdit_24->setText(query.value(3).toString());
            ui->lineEdit_30->setText(query.value(4).toString());
            ui->lineEdit_36->setText(query.value(5).toString());
            ui->lineEdit_42->setText(query.value(6).toString());
        }

        query.prepare("select mix1,mix2,mix3,mix4,mix5,mix6,mix7 FROM DNA where name=:name");
        query.bindValue(":name",temp);
        query.exec();
        while(query.next())
        {
            ui->lineEdit_8->setText(query.value(0).toString());
            ui->lineEdit_13->setText(query.value(1).toString());
            ui->lineEdit_19->setText(query.value(2).toString());
            ui->lineEdit_25->setText(query.value(3).toString());
            ui->lineEdit_31->setText(query.value(4).toString());
            ui->lineEdit_37->setText(query.value(5).toString());
            ui->lineEdit_43->setText(query.value(6).toString());
        }
        query.prepare("select mag1,mag2,mag3,mag4,mag5,mag6,mag7 FROM DNA where name=:name");
        query.bindValue(":name",temp);
        query.exec();
        while(query.next())
        {
            ui->lineEdit_9->setText(query.value(0).toString());
            ui->lineEdit_15->setText(query.value(1).toString());
            ui->lineEdit_21->setText(query.value(2).toString());
            ui->lineEdit_27->setText(query.value(3).toString());
            ui->lineEdit_33->setText(query.value(4).toString());
            ui->lineEdit_39->setText(query.value(5).toString());
            ui->lineEdit_45->setText(query.value(6).toString());
        }
        query.prepare("select vol1,vol2,vol3,vol4,vol5,vol6,vol7 FROM DNA where name=:name");
        query.bindValue(":name",temp);
        query.exec();
        while(query.next())
        {
            ui->lineEdit_10->setText(query.value(0).toString());
            ui->lineEdit_16->setText(query.value(1).toString());
            ui->lineEdit_22->setText(query.value(2).toString());
            ui->lineEdit_28->setText(query.value(3).toString());
            ui->lineEdit_34->setText(query.value(4).toString());
            ui->lineEdit_40->setText(query.value(5).toString());
            ui->lineEdit_46->setText(query.value(6).toString());
        }
        query.prepare("select spd1,spd2,spd3,spd4,spd5,spd6,spd7 FROM DNA where name=:name");
        query.bindValue(":name",temp);
        query.exec();
        while(query.next())
        {
            ui->comboBox_6->setCurrentIndex(query.value(0).toInt()-1);
            ui->comboBox_7->setCurrentIndex(query.value(1).toInt()-1);
            ui->comboBox_9->setCurrentIndex(query.value(2).toInt()-1);
            ui->comboBox_11->setCurrentIndex(query.value(3).toInt()-1);
            ui->comboBox_13->setCurrentIndex(query.value(4).toInt()-1);
            ui->comboBox_15->setCurrentIndex(query.value(5).toInt()-1);
            ui->comboBox_17->setCurrentIndex(query.value(6).toInt()-1);
        }
        query.prepare("select temp1,temp2,temp3,temp4,temp5,temp6,temp7 FROM DNA where name=:name");
        query.bindValue(":name",temp);
        query.exec();
        while(query.next())
        {
            ui->lineEdit_11->setText(query.value(0).toString());
            ui->lineEdit_17->setText(query.value(1).toString());
            ui->lineEdit_23->setText(query.value(2).toString());
            ui->lineEdit_29->setText(query.value(3).toString());
            ui->lineEdit_35->setText(query.value(4).toString());
            ui->lineEdit_41->setText(query.value(5).toString());
            ui->lineEdit_47->setText(query.value(6).toString());
        }


    }


    QByteArray bytes = name.toUtf8();
    int length = bytes.size();
    //qDebug()<<"Length = "<<length;
    if(length>0)
    {
        int clen=ui->comboBox->count();
        int cmpstat=0;
        for(int i=0;i<clen;i++)
        {
            if(name==ui->comboBox->itemText(i))
                cmpstat=1;
        }
        if(cmpstat==1)
        {
            msg.setText("Name Exists");
            msg.exec();
        }
        else
            ui->stackedWidget->setCurrentIndex(2);
    }

    else {
        msg.setText("Empty Name");
        msg.exec();
    }



}

void MainWindow::on_toolButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    QString name,p1name,p2name,p3name,p4name,p5name,p6name,p7name;
    int p1pos,p1wait,p1mix,p1mag,p1vol,p1spd,p1temp;
    int p2pos,p2wait,p2mix,p2mag,p2vol,p2spd,p2temp;
    int p3pos,p3wait,p3mix,p3mag,p3vol,p3spd,p3temp;
    int p4pos,p4wait,p4mix,p4mag,p4vol,p4spd,p4temp;
    int p5pos,p5wait,p5mix,p5mag,p5vol,p5spd,p5temp;
    int p6pos,p6wait,p6mix,p6mag,p6vol,p6spd,p6temp;
    int p7pos,p7wait,p7mix,p7mag,p7vol,p7spd,p7temp;

    name=ui->lineEdit->text();
    p1name=ui->lineEdit_3->text();
    p2name=ui->lineEdit_14->text();
    p3name=ui->lineEdit_20->text();
    p4name=ui->lineEdit_26->text();
    p5name=ui->lineEdit_32->text();
    p6name=ui->lineEdit_38->text();
    p7name=ui->lineEdit_44->text();

    p1pos=ui->comboBox_3->currentText().toInt();
    p2pos=ui->comboBox_8->currentText().toInt();
    p3pos=ui->comboBox_10->currentText().toInt();
    p4pos=ui->comboBox_12->currentText().toInt();
    p5pos=ui->comboBox_14->currentText().toInt();
    p6pos=ui->comboBox_16->currentText().toInt();
    p7pos=ui->comboBox_18->currentText().toInt();

    p1wait=ui->lineEdit_4->text().toInt();
    p2wait=ui->lineEdit_12->text().toInt();
    p3wait=ui->lineEdit_18->text().toInt();
    p4wait=ui->lineEdit_24->text().toInt();
    p5wait=ui->lineEdit_30->text().toInt();
    p6wait=ui->lineEdit_36->text().toInt();
    p7wait=ui->lineEdit_42->text().toInt();

    p1mix=ui->lineEdit_8->text().toInt();
    p2mix=ui->lineEdit_13->text().toInt();
    p3mix=ui->lineEdit_19->text().toInt();
    p4mix=ui->lineEdit_25->text().toInt();
    p5mix=ui->lineEdit_31->text().toInt();
    p6mix=ui->lineEdit_37->text().toInt();
    p7mix=ui->lineEdit_43->text().toInt();

    p1mag=ui->lineEdit_9->text().toInt();
    p2mag=ui->lineEdit_15->text().toInt();
    p3mag=ui->lineEdit_21->text().toInt();
    p4mag=ui->lineEdit_27->text().toInt();
    p5mag=ui->lineEdit_33->text().toInt();
    p6mag=ui->lineEdit_39->text().toInt();
    p7mag=ui->lineEdit_45->text().toInt();

    p1vol=ui->lineEdit_10->text().toInt();
    p2vol=ui->lineEdit_16->text().toInt();
    p3vol=ui->lineEdit_22->text().toInt();
    p4vol=ui->lineEdit_28->text().toInt();
    p5vol=ui->lineEdit_34->text().toInt();
    p6vol=ui->lineEdit_40->text().toInt();
    p7vol=ui->lineEdit_46->text().toInt();

    p1spd=ui->comboBox_6->currentText().toInt();
    p2spd=ui->comboBox_7->currentText().toInt();
    p3spd=ui->comboBox_9->currentText().toInt();
    p4spd=ui->comboBox_11->currentText().toInt();
    p5spd=ui->comboBox_13->currentText().toInt();
    p6spd=ui->comboBox_15->currentText().toInt();
    p7spd=ui->comboBox_17->currentText().toInt();

    p1temp=ui->lineEdit_11->text().toInt();
    p2temp=ui->lineEdit_17->text().toInt();
    p3temp=ui->lineEdit_23->text().toInt();
    p4temp=ui->lineEdit_29->text().toInt();
    p5temp=ui->lineEdit_35->text().toInt();
    p6temp=ui->lineEdit_41->text().toInt();
    p7temp=ui->lineEdit_47->text().toInt();


    QSqlQuery query;
    if(from_edit==0)
    {
        query.prepare("insert into DNA(name,pname1,pname2,pname3,pname4,pname5,pname6,pname7) values(:name,:pname1,:pname2,:pname3,:pname4,:pname5,:pname6,:pname7)");
        query.bindValue(":name",name);
        query.bindValue(":pname1",p1name);
        query.bindValue(":pname2",p2name);
        query.bindValue(":pname3",p3name);
        query.bindValue(":pname4",p4name);
        query.bindValue(":pname5",p5name);
        query.bindValue(":pname6",p6name);
        query.bindValue(":pname7",p7name);
        query.exec();
    }
    else
    {
        query.prepare("update DNA set pname1=:pname1,pname2=:pname2,pname3=:pname3,pname4=:pname4,pname5=:pname5,pname6=:pname6,pname7=:pname7 where name=:name");
        query.bindValue(":name",name);
        query.bindValue(":pname1",p1name);
        query.bindValue(":pname2",p2name);
        query.bindValue(":pname3",p3name);
        query.bindValue(":pname4",p4name);
        query.bindValue(":pname5",p5name);
        query.bindValue(":pname6",p6name);
        query.bindValue(":pname7",p7name);
        query.exec();
        from_edit=0;
    }



    query.prepare("update DNA set well1=:p1pos,well2=:p2pos,well3=:p3pos,well4=:p4pos,well5=:p5pos,well6=:p6pos,well7=:p7pos where name=:name");
    query.bindValue(":p1pos",p1pos);
    query.bindValue(":p2pos",p2pos);
    query.bindValue(":p3pos",p3pos);
    query.bindValue(":p4pos",p4pos);
    query.bindValue(":p5pos",p5pos);
    query.bindValue(":p6pos",p6pos);
    query.bindValue(":p7pos",p7pos);
    query.bindValue(":name",name);
    query.exec();

    query.prepare("update DNA set wait1=:p1wait,wait2=:p2wait,wait3=:p3wait,wait4=:p4wait,wait5=:p5wait,wait6=:p6wait,wait7=:p7wait where name=:name");
    query.bindValue(":p1wait",p1wait);
    query.bindValue(":p2wait",p2wait);
    query.bindValue(":p3wait",p3wait);
    query.bindValue(":p4wait",p4wait);
    query.bindValue(":p5wait",p5wait);
    query.bindValue(":p6wait",p6wait);
    query.bindValue(":p7wait",p7wait);
    query.bindValue(":name",name);
    query.exec();

    query.prepare("update DNA set mix1=:p1mix,mix2=:p2mix,mix3=:p3mix,mix4=:p4mix,mix5=:p5mix,mix6=:p6mix,mix7=:p7mix where name=:name");
    query.bindValue(":p1mix",p1mix);
    query.bindValue(":p2mix",p2mix);
    query.bindValue(":p3mix",p3mix);
    query.bindValue(":p4mix",p4mix);
    query.bindValue(":p5mix",p5mix);
    query.bindValue(":p6mix",p6mix);
    query.bindValue(":p7mix",p7mix);
    query.bindValue(":name",name);
    query.exec();

    query.prepare("update DNA set mag1=:p1mag,mag2=:p2mag,mag3=:p3mag,mag4=:p4mag,mag5=:p5mag,mag6=:p6mag,mag7=:p7mag where name=:name");
    query.bindValue(":p1mag",p1mag);
    query.bindValue(":p2mag",p2mag);
    query.bindValue(":p3mag",p3mag);
    query.bindValue(":p4mag",p4mag);
    query.bindValue(":p5mag",p5mag);
    query.bindValue(":p6mag",p6mag);
    query.bindValue(":p7mag",p7mag);
    query.bindValue(":name",name);
    query.exec();

    query.prepare("update DNA set vol1=:p1vol,vol2=:p2vol,vol3=:p3vol,vol4=:p4vol,vol5=:p5vol,vol6=:p6vol,vol7=:p7vol where name=:name");
    query.bindValue(":p1vol",p1vol);
    query.bindValue(":p2vol",p2vol);
    query.bindValue(":p3vol",p3vol);
    query.bindValue(":p4vol",p4vol);
    query.bindValue(":p5vol",p5vol);
    query.bindValue(":p6vol",p6vol);
    query.bindValue(":p7vol",p7vol);
    query.bindValue(":name",name);
    query.exec();

    query.prepare("update DNA set spd1=:p1spd,spd2=:p2spd,spd3=:p3spd,spd4=:p4spd,spd5=:p5spd,spd6=:p6spd,spd7=:p7spd where name=:name");
    query.bindValue(":p1spd",p1spd);
    query.bindValue(":p2spd",p2spd);
    query.bindValue(":p3spd",p3spd);
    query.bindValue(":p4spd",p4spd);
    query.bindValue(":p5spd",p5spd);
    query.bindValue(":p6spd",p6spd);
    query.bindValue(":p7spd",p7spd);
    query.bindValue(":name",name);
    query.exec();

    query.prepare("update DNA set temp1=:p1temp,temp2=:p2temp,temp3=:p3temp,temp4=:p4temp,temp5=:p5temp,temp6=:p6temp,temp7=:p7temp where name=:name");
    query.bindValue(":p1temp",p1temp);
    query.bindValue(":p2temp",p2temp);
    query.bindValue(":p3temp",p3temp);
    query.bindValue(":p4temp",p4temp);
    query.bindValue(":p5temp",p5temp);
    query.bindValue(":p6temp",p6temp);
    query.bindValue(":p7temp",p7temp);
    query.bindValue(":name",name);
    query.exec();



    query.prepare("SELECT name FROM DNA");
    query.exec();
    ui->listWidget->clear();
    while(query.next())
    {
        ui->listWidget->addItem(query.value(0).toString());
    }

}

void MainWindow::on_toolButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_toolButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    //const QString& s = ui->listWidget->currentItem()->text();
    //ui->label_91->setText(s);
    QString name;
    name=ui->listWidget->currentItem()->text();
    ui->label_91->setText(name);
    //qDebug()<<selitem;
    QSqlQuery query;
    //step 1
    query.prepare("select pname1,well1,wait1,mix1,mag1,vol1,spd1,temp1 FROM DNA where name=:name");
    query.bindValue(":name",name);
    query.exec();
    QString processname1;
    int pos1,wait1,mix1,mag1,vol1,spd1,temp1;
    while(query.next())
    {
        processname1=query.value(0).toString();
        pos1=query.value(1).toInt()-1;
        wait1=query.value(2).toInt();
        mix1=query.value(3).toInt();
        mag1=query.value(4).toInt();
        vol1=query.value(5).toInt();
        spd1=query.value(6).toInt();
        temp1=query.value(7).toInt();
    }
    //step 2
    query.prepare("select pname2,well2,wait2,mix2,mag2,vol2,spd2,temp2 FROM DNA where name=:name");
    query.bindValue(":name",name);
    query.exec();
    QString processname2;
    int pos2,wait2,mix2,mag2,vol2,spd2,temp2;
    while(query.next())
    {
        processname2=query.value(0).toString();
        pos2=query.value(1).toInt()-1;
        wait2=query.value(2).toInt();
        mix2=query.value(3).toInt();
        mag2=query.value(4).toInt();
        vol2=query.value(5).toInt();
        spd2=query.value(6).toInt();
        temp2=query.value(7).toInt();
    }
    //step 3
    query.prepare("select pname3,well3,wait3,mix3,mag3,vol3,spd3,temp3 FROM DNA where name=:name");
    query.bindValue(":name",name);
    query.exec();
    QString processname3;
    int pos3,wait3,mix3,mag3,vol3,spd3,temp3;
    while(query.next())
    {
        processname3=query.value(0).toString();
        pos3=query.value(1).toInt()-1;
        wait3=query.value(2).toInt();
        mix3=query.value(3).toInt();
        mag3=query.value(4).toInt();
        vol3=query.value(5).toInt();
        spd3=query.value(6).toInt();
        temp3=query.value(7).toInt();
    }
    //step 4
    query.prepare("select pname4,well4,wait4,mix4,mag4,vol4,spd4,temp4 FROM DNA where name=:name");
    query.bindValue(":name",name);
    query.exec();
    QString processname4;
    int pos4,wait4,mix4,mag4,vol4,spd4,temp4;
    while(query.next())
    {
        processname4=query.value(0).toString();
        pos4=query.value(1).toInt()-1;
        wait4=query.value(2).toInt();
        mix4=query.value(3).toInt();
        mag4=query.value(4).toInt();
        vol4=query.value(5).toInt();
        spd4=query.value(6).toInt();
        temp4=query.value(7).toInt();
    }
    //step 5
    query.prepare("select pname5,well5,wait5,mix5,mag5,vol5,spd5,temp5 FROM DNA where name=:name");
    query.bindValue(":name",name);
    query.exec();
    QString processname5;
    int pos5,wait5,mix5,mag5,vol5,spd5,temp5;
    while(query.next())
    {
        processname5=query.value(0).toString();
        pos5=query.value(1).toInt()-1;
        wait5=query.value(2).toInt();
        mix5=query.value(3).toInt();
        mag5=query.value(4).toInt();
        vol5=query.value(5).toInt();
        spd5=query.value(6).toInt();
        temp5=query.value(7).toInt();
    }
    //step 6
    query.prepare("select pname6,well6,wait6,mix6,mag6,vol6,spd6,temp6 FROM DNA where name=:name");
    query.bindValue(":name",name);
    query.exec();
    QString processname6;
    int pos6,wait6,mix6,mag6,vol6,spd6,temp6;
    while(query.next())
    {
        processname6=query.value(0).toString();
        pos6=query.value(1).toInt()-1;
        wait6=query.value(2).toInt();
        mix6=query.value(3).toInt();
        mag6=query.value(4).toInt();
        vol6=query.value(5).toInt();
        spd6=query.value(6).toInt();
        temp6=query.value(7).toInt();
    }
    //step 7
    query.prepare("select pname7,well7,wait7,mix7,mag7,vol7,spd7,temp7 FROM DNA where name=:name");
    query.bindValue(":name",name);
    query.exec();
    QString processname7;
    int pos7,wait7,mix7,mag7,vol7,spd7,temp7;
    while(query.next())
    {
        processname7=query.value(0).toString();
        pos7=query.value(1).toInt()-1;
        wait7=query.value(2).toInt();
        mix7=query.value(3).toInt();
        mag7=query.value(4).toInt();
        vol7=query.value(5).toInt();
        spd7=query.value(6).toInt();
        temp7=query.value(7).toInt();
    }

    int cur_pos=1;
    int mov_pos=0;
    QString s="";

    array[0]=processname1;
    array[1]="mhmm";
    array[2]="shm";
    array[3]="bhm";

    //step 1
    s = QString::number(temp1);
    array[4]="W "+s+" 0 "+s+" 0 "+s+" 0 "+s+" 0";
    if(pos1>cur_pos)
    {
        mov_pos=pos1-cur_pos;
        s = QString::number(mov_pos);
        array[5]="bmf "+s;
        cur_pos=pos1;
    }
    else if(pos1<cur_pos)
    {
        mov_pos=cur_pos-pos1;
        s = QString::number(mov_pos);
        array[5]="bmb "+s;
        cur_pos=pos1;
    }
    else
    {
        array[5]="bmb 0";
    }
    array[6]="smf 1";
    s = QString::number(wait1);
    array[7]="idl "+s;
    s = QString::number(mix1);
    array[8]="mix "+s+" 1";
    array[9]="mmf 1";
    s = QString::number(mag1);
    array[10]="idl "+s;
    array[11]="msb 1";

    //step 2
    array[12]=processname2;
    s = QString::number(temp2);
    array[13]="W "+s+" 0 "+s+" 0 "+s+" 0 "+s+" 0";
    if(pos2>cur_pos)
    {
        mov_pos=pos2-cur_pos;
        s = QString::number(mov_pos);
        array[14]="bmf "+s;
        cur_pos=pos2;
    }
    else if(pos2<cur_pos)
    {
        mov_pos=cur_pos-pos2;
        s = QString::number(mov_pos);
        array[14]="bmb "+s;
        cur_pos=pos2;
    }
    else
    {
        array[14]="bmb 0";
    }
    array[15]="msf 1";
    array[16]="mhm";
    s = QString::number(wait2);
    array[17]="idl "+s;
    s = QString::number(mix2);
    array[18]="mix "+s+" 1";
    array[19]="mmf 1";
    s = QString::number(mag2);
    array[20]="idl "+s;
    array[21]="msb 1";


    //step 3
    array[22]=processname3;
    s = QString::number(temp3);
    array[23]="W "+s+" 0 "+s+" 0 "+s+" 0 "+s+" 0";
    if(pos3>cur_pos)
    {
        mov_pos=pos3-cur_pos;
        s = QString::number(mov_pos);
        array[24]="bmf "+s;
        cur_pos=pos3;
    }
    else if(pos3<cur_pos)
    {
        mov_pos=cur_pos-pos3;
        s = QString::number(mov_pos);
        array[24]="bmb "+s;
        cur_pos=pos3;
    }
    else
    {
        array[24]="bmb 0";
    }
    array[25]="msf 1";
    array[26]="mhm";
    s = QString::number(wait3);
    array[27]="idl "+s;
    s = QString::number(mix3);
    array[28]="mix "+s+" 1";
    array[29]="mmf 1";
    s = QString::number(mag3);
    array[30]="idl "+s;
    array[31]="msb 1";


    //step 4
    array[32]=processname4;
    s = QString::number(temp4);
    array[33]="W 0 "+s+" 0 "+s+" 0 "+s+" 0 "+s;
    if(pos4>cur_pos)
    {
        mov_pos=pos4-cur_pos;
        s = QString::number(mov_pos);
        array[34]="bmf "+s;
        cur_pos=pos4;
    }
    else if(pos4<cur_pos)
    {
        mov_pos=cur_pos-pos4;
        s = QString::number(mov_pos);
        array[34]="bmb "+s;
        cur_pos=pos4;
    }
    else
    {
        array[34]="bmb 0";
    }
    array[35]="msf 1";
    array[36]="mhm";
    s = QString::number(wait4);
    array[37]="idl "+s;
    s = QString::number(mix4);
    array[38]="mix "+s+" 1";
    array[39]="mmf 1";
    s = QString::number(mag4);
    array[40]="idl "+s;
    array[41]="msb 1";


    //step 5
    array[42]=processname5;
    s = QString::number(temp5);
    array[43]="W 0 "+s+" 0 "+s+" 0 "+s+" 0 "+s;
    if(pos5>cur_pos)
    {
        mov_pos=pos5-cur_pos;
        s = QString::number(mov_pos);
        array[44]="bmf "+s;
        cur_pos=pos5;
    }
    else if(pos5<cur_pos)
    {
        mov_pos=cur_pos-pos5;
        s = QString::number(mov_pos);
        array[44]="bmb "+s;
        cur_pos=pos5;
    }
    else
    {
        array[44]="bmb 0";
    }
    array[45]="msf 1";
    array[46]="mhm";
    s = QString::number(wait5);
    array[47]="idl "+s;
    s = QString::number(mix5);
    array[48]="mix "+s+" 1";
    array[49]="mmf 1";
    s = QString::number(mag5);
    array[50]="idl "+s;
    array[51]="msb 1";


    //step 6
    array[52]=processname6;
    s = QString::number(temp6);
    array[53]="W 0 "+s+" 0 "+s+" 0 "+s+" 0 "+s;
    if(pos6>cur_pos)
    {
        mov_pos=pos6-cur_pos;
        s = QString::number(mov_pos);
        array[54]="bmf "+s;
        cur_pos=pos6;
    }
    else if(pos6<cur_pos)
    {
        mov_pos=cur_pos-pos6;
        s = QString::number(mov_pos);
        array[54]="bmb "+s;
        cur_pos=pos6;
    }
    else
    {
        array[54]="bmb 0";
    }
    array[55]="msf 1";
    array[56]="mhm";
    s = QString::number(wait6);
    array[57]="idl "+s;
    s = QString::number(mix6);
    array[58]="mix "+s+" 1";
    array[59]="mmf 1";
    s = QString::number(mag6);
    array[60]="idl "+s;
    array[61]="msb 1";



    //step 7
    array[62]=processname7;
    s = QString::number(temp7);
    array[63]="W 0 "+s+" 0 "+s+" 0 "+s+" 0 "+s;
    if(pos7>cur_pos)
    {
        mov_pos=pos7-cur_pos;
        s = QString::number(mov_pos);
        array[64]="bmf "+s;
        cur_pos=pos7;
    }
    else if(pos7<cur_pos)
    {
        mov_pos=cur_pos-pos7;
        s = QString::number(mov_pos);
        array[64]="bmb "+s;
        cur_pos=pos7;
    }
    else
    {
        array[64]="bmb 0";
    }
    array[65]="msf 1";
    array[66]="mhm";
    s = QString::number(wait7);
    array[67]="idl "+s;
    s = QString::number(mix7);
    array[68]="mix "+s+" 1";
    array[69]="mmf 1";
    s = QString::number(mag7);
    array[70]="idl "+s;
    array[71]="msb 1";

    for(int i=0;i<72;i++)
    {
        qDebug()<<array[i];
    }
    ui->label_91->setText(name);
    ui->label_14->setText(processname1);

}

void MainWindow::on_toolButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_toolButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_toolButton_26_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_pushButton_32_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_pushButton_66_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_26_clicked()
{
    if (opt==1)
    {
        ui->stackedWidget->setCurrentIndex(1);
        ui->lineEdit->setText(ui->lineEdit_145->text());
    }
    else if (opt==2)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_3->setText(ui->lineEdit_145->text());
    }
    else if (opt==3)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_14->setText(ui->lineEdit_145->text());
    }
    else if (opt==4)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_20->setText(ui->lineEdit_145->text());
    }
    else if (opt==5)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_26->setText(ui->lineEdit_145->text());
    }
    else if (opt==6)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_32->setText(ui->lineEdit_145->text());
    }
    else if (opt==7)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_38->setText(ui->lineEdit_145->text());
    }
    else if (opt==8)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_44->setText(ui->lineEdit_145->text());
    }
    else if (opt==9)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_4->setText(ui->lineEdit_145->text());
    }
    else if (opt==10)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_12->setText(ui->lineEdit_145->text());
    }
    else if (opt==11)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_18->setText(ui->lineEdit_145->text());
    }
    else if (opt==12)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_24->setText(ui->lineEdit_145->text());
    }
    else if (opt==13)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_30->setText(ui->lineEdit_145->text());
    }
    else if (opt==14)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_36->setText(ui->lineEdit_145->text());
    }
    else if (opt==15)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_42->setText(ui->lineEdit_145->text());
    }

    else if (opt==16)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_8->setText(ui->lineEdit_145->text());
    }
    else if (opt==17)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_13->setText(ui->lineEdit_145->text());
    }
    else if (opt==18)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_19->setText(ui->lineEdit_145->text());
    }
    else if (opt==19)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_25->setText(ui->lineEdit_145->text());
    }
    else if (opt==20)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_31->setText(ui->lineEdit_145->text());
    }
    else if (opt==21)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_37->setText(ui->lineEdit_145->text());
    }
    else if (opt==22)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_43->setText(ui->lineEdit_145->text());
    }

    else if (opt==23)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_9->setText(ui->lineEdit_145->text());
    }
    else if (opt==24)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_15->setText(ui->lineEdit_145->text());
    }
    else if (opt==25)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_21->setText(ui->lineEdit_145->text());
    }
    else if (opt==26)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_27->setText(ui->lineEdit_145->text());
    }
    else if (opt==27)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_33->setText(ui->lineEdit_145->text());
    }
    else if (opt==28)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_39->setText(ui->lineEdit_145->text());
    }
    else if (opt==29)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_45->setText(ui->lineEdit_145->text());
    }

    else if (opt==30)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_10->setText(ui->lineEdit_145->text());
    }
    else if (opt==31)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_16->setText(ui->lineEdit_145->text());
    }
    else if (opt==32)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_22->setText(ui->lineEdit_145->text());
    }
    else if (opt==33)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_28->setText(ui->lineEdit_145->text());
    }
    else if (opt==34)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_34->setText(ui->lineEdit_145->text());
    }
    else if (opt==35)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_40->setText(ui->lineEdit_145->text());
    }
    else if (opt==36)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_46->setText(ui->lineEdit_145->text());
    }

    else if (opt==37)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_11->setText(ui->lineEdit_145->text());
    }
    else if (opt==38)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_17->setText(ui->lineEdit_145->text());
    }
    else if (opt==39)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_23->setText(ui->lineEdit_145->text());
    }
    else if (opt==40)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_29->setText(ui->lineEdit_145->text());
    }
    else if (opt==41)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_35->setText(ui->lineEdit_145->text());
    }
    else if (opt==42)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_41->setText(ui->lineEdit_145->text());
    }
    else if (opt==43)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_47->setText(ui->lineEdit_145->text());
    }
    else if (opt==44)
    {
        ui->stackedWidget->setCurrentIndex(4);
        ui->lineEdit_144->setText(ui->lineEdit_145->text());
    }
}

void MainWindow::on_pushButton_95_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_99_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_104_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_88_clicked()
{
    on_pushButton_26_clicked();
}

void MainWindow::on_pushButton_136_clicked()
{
    on_pushButton_26_clicked();
}

void MainWindow::on_pushButton_139_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_111_clicked()
{
    opt=2;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->lineEdit_145->setText(ui->lineEdit_3->text());

}

void MainWindow::on_pushButton_112_clicked()
{
    opt=3;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->lineEdit_145->setText(ui->lineEdit_14->text());
}

void MainWindow::on_pushButton_113_clicked()
{
    opt=4;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->lineEdit_145->setText(ui->lineEdit_20->text());
}

void MainWindow::on_pushButton_117_clicked()
{
    opt=5;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->lineEdit_145->setText(ui->lineEdit_26->text());
}

void MainWindow::on_pushButton_118_clicked()
{
    opt=6;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->lineEdit_145->setText(ui->lineEdit_32->text());
}

void MainWindow::on_pushButton_119_clicked()
{
    opt=7;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->lineEdit_145->setText(ui->lineEdit_38->text());
}

void MainWindow::on_pushButton_120_clicked()
{
    opt=8;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->lineEdit_145->setText(ui->lineEdit_44->text());
}

void MainWindow::on_pushButton_122_clicked()
{
    opt=9;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_4->text());
}

void MainWindow::on_pushButton_129_clicked()
{
    opt=10;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_12->text());
}

void MainWindow::on_pushButton_124_clicked()
{
    opt=11;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_18->text());
}

void MainWindow::on_pushButton_127_clicked()
{
    opt=12;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_24->text());
}

void MainWindow::on_pushButton_126_clicked()
{
    opt=13;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_30->text());
}

void MainWindow::on_pushButton_130_clicked()
{
    opt=14;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_36->text());
}

void MainWindow::on_pushButton_121_clicked()
{
    opt=15;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_42->text());
}

void MainWindow::on_pushButton_131_clicked()
{
    opt=17;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_13->text());
}

void MainWindow::on_pushButton_132_clicked()
{
    opt=16;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_8->text());
}

void MainWindow::on_pushButton_142_clicked()
{
    opt=18;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_19->text());
}

void MainWindow::on_pushButton_135_clicked()
{
    opt=19;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_25->text());
}

void MainWindow::on_pushButton_133_clicked()
{
    opt=20;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_31->text());
}

void MainWindow::on_pushButton_144_clicked()
{
    opt=21;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_37->text());
}

void MainWindow::on_pushButton_143_clicked()
{
    opt=22;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_43->text());
}

void MainWindow::on_pushButton_146_clicked()
{
    opt=23;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_9->text());
}

void MainWindow::on_pushButton_145_clicked()
{
    opt=24;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_15->text());
}

void MainWindow::on_pushButton_149_clicked()
{
    opt=25;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_21->text());
}

void MainWindow::on_pushButton_148_clicked()
{
    opt=26;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_27->text());
}

void MainWindow::on_pushButton_147_clicked()
{
    opt=27;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_33->text());
}

void MainWindow::on_pushButton_151_clicked()
{
    opt=28;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_39->text());
}

void MainWindow::on_pushButton_150_clicked()
{
    opt=29;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_45->text());
}

void MainWindow::on_pushButton_153_clicked()
{
    opt=30;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_10->text());
}

void MainWindow::on_pushButton_152_clicked()
{
    opt=31;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_16->text());
}

void MainWindow::on_pushButton_156_clicked()
{
    opt=32;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_22->text());
}

void MainWindow::on_pushButton_155_clicked()
{
    opt=33;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_28->text());
}

void MainWindow::on_pushButton_154_clicked()
{
    opt=34;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_34->text());
}

void MainWindow::on_pushButton_158_clicked()
{
    opt=35;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_40->text());
}

void MainWindow::on_pushButton_157_clicked()
{
    opt=36;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_46->text());
}

void MainWindow::on_pushButton_164_clicked()
{
    opt=37;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_11->text());
}

void MainWindow::on_pushButton_162_clicked()
{
    opt=38;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_17->text());
}

void MainWindow::on_pushButton_161_clicked()
{
    opt=39;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_23->text());
}

void MainWindow::on_pushButton_159_clicked()
{
    opt=40;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_29->text());
}

void MainWindow::on_pushButton_160_clicked()
{
    opt=41;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_35->text());
}

void MainWindow::on_pushButton_163_clicked()
{
    opt=42;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_41->text());
}

void MainWindow::on_pushButton_165_clicked()
{
    opt=43;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_47->text());
}

void MainWindow::on_pushButton_166_clicked()
{
    opt=44;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->lineEdit_145->setText(ui->lineEdit_144->text());
}

void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton->text());
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->lineEdit_145->backspace();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_2->text());
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_6->text());
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_5->text());
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_14->text());
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_12->text());
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_13->text());
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_11->text());
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_18->text());
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_16->text());
}

void MainWindow::on_pushButton_27_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_27->text());
}

void MainWindow::on_pushButton_20_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_20->text());
}

void MainWindow::on_pushButton_21_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_21->text());
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_19->text());
}

void MainWindow::on_pushButton_28_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_28->text());
}

void MainWindow::on_pushButton_25_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_25->text());
}

void MainWindow::on_pushButton_22_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_22->text());
}

void MainWindow::on_pushButton_23_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_23->text());
}

void MainWindow::on_pushButton_29_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_29->text());
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_4->text());
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_8->text());
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_7->text());
}

void MainWindow::on_pushButton_33_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_33->text());
}

void MainWindow::on_pushButton_34_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_34->text());
}

void MainWindow::on_pushButton_30_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_30->text());
}

void MainWindow::on_pushButton_31_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_31->text());
}

void MainWindow::on_pushButton_24_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_24->text());
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_17->text());
}

void MainWindow::on_pushButton_68_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+" ");
}

void MainWindow::on_pushButton_69_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_69->text());
}

void MainWindow::on_pushButton_67_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_67->text());
}

void MainWindow::on_pushButton_65_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_65->text());
}

void MainWindow::on_pushButton_70_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_70->text());
}

void MainWindow::on_pushButton_79_clicked()
{
    ui->lineEdit_145->backspace();
}

void MainWindow::on_pushButton_109_clicked()
{
    ui->lineEdit_145->backspace();
}

void MainWindow::on_pushButton_71_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_71->text());
}

void MainWindow::on_pushButton_72_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_72->text());
}

void MainWindow::on_pushButton_74_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_74->text());
}

void MainWindow::on_pushButton_73_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_73->text());
}

void MainWindow::on_pushButton_78_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_78->text());
}

void MainWindow::on_pushButton_76_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_76->text());
}

void MainWindow::on_pushButton_77_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_77->text());
}

void MainWindow::on_pushButton_75_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_75->text());
}

void MainWindow::on_pushButton_81_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_81->text());
}

void MainWindow::on_pushButton_80_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_80->text());
}

void MainWindow::on_pushButton_89_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_89->text());
}

void MainWindow::on_pushButton_83_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_83->text());
}

void MainWindow::on_pushButton_84_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_84->text());
}

void MainWindow::on_pushButton_82_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_82->text());
}

void MainWindow::on_pushButton_90_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_90->text());
}

void MainWindow::on_pushButton_87_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_87->text());
}

void MainWindow::on_pushButton_85_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_85->text());
}

void MainWindow::on_pushButton_86_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_86->text());
}

void MainWindow::on_pushButton_91_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_91->text());
}

void MainWindow::on_pushButton_101_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_101->text());
}

void MainWindow::on_pushButton_98_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_98->text());
}

void MainWindow::on_pushButton_93_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_93->text());
}

void MainWindow::on_pushButton_100_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_100->text());
}

void MainWindow::on_pushButton_102_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_102->text());
}

void MainWindow::on_pushButton_96_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_96->text());
}

void MainWindow::on_pushButton_97_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_97->text());
}

void MainWindow::on_pushButton_92_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_92->text());
}

void MainWindow::on_pushButton_94_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_94->text());
}

void MainWindow::on_pushButton_106_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+" ");
}

void MainWindow::on_pushButton_107_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_107->text());
}

void MainWindow::on_pushButton_105_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_105->text());
}

void MainWindow::on_pushButton_103_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_103->text());
}

void MainWindow::on_pushButton_108_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_108->text());
}

void MainWindow::on_pushButton_116_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_116->text());
}

void MainWindow::on_pushButton_114_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_114->text());
}

void MainWindow::on_pushButton_115_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_115->text());
}

void MainWindow::on_pushButton_128_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_128->text());
}

void MainWindow::on_pushButton_125_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_125->text());
}

void MainWindow::on_pushButton_123_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_123->text());
}

void MainWindow::on_pushButton_138_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_138->text());
}

void MainWindow::on_pushButton_140_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_140->text());
}

void MainWindow::on_pushButton_134_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_134->text());
}

void MainWindow::on_pushButton_141_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_141->text());
}

void MainWindow::on_pushButton_137_clicked()
{
    ui->lineEdit_145->setText(ui->lineEdit_145->text()+ui->pushButton_137->text());
}

void MainWindow::on_toolButton_5_clicked()
{
    QString selitem;
    selitem=ui->listWidget->currentItem()->text();
    //qDebug()<<selitem;
    QSqlQuery query;
    query.prepare("delete FROM DNA where name=:name");
    query.bindValue(":name",selitem);
    query.exec();

    query.prepare("SELECT name FROM DNA");
    query.exec();
    ui->listWidget->clear();
    while(query.next())
    {
        ui->listWidget->addItem(query.value(0).toString());
    }
}

void MainWindow::on_toolButton_4_clicked()
{
    QString temp;
    temp=ui->listWidget->currentItem()->text();
    //qDebug()<<selitem;
    QSqlQuery query;
    query.prepare("select pname1,pname2,pname3,pname4,pname5,pname6,pname7 FROM DNA where name=:name");
    query.bindValue(":name",temp);
    query.exec();
    while(query.next())
    {
        ui->lineEdit_3->setText(query.value(0).toString());
        ui->lineEdit_14->setText(query.value(1).toString());
        ui->lineEdit_20->setText(query.value(2).toString());
        ui->lineEdit_26->setText(query.value(3).toString());
        ui->lineEdit_32->setText(query.value(4).toString());
        ui->lineEdit_38->setText(query.value(5).toString());
        ui->lineEdit_44->setText(query.value(6).toString());
    }

    query.prepare("select well1,well2,well3,well4,well5,well6,well7 FROM DNA where name=:name");
    query.bindValue(":name",temp);
    query.exec();
    while(query.next())
    {
        ui->comboBox_3->setCurrentIndex(query.value(0).toInt()-1);
        ui->comboBox_8->setCurrentIndex(query.value(1).toInt()-1);
        ui->comboBox_10->setCurrentIndex(query.value(2).toInt()-1);
        ui->comboBox_12->setCurrentIndex(query.value(3).toInt()-1);
        ui->comboBox_14->setCurrentIndex(query.value(4).toInt()-1);
        ui->comboBox_16->setCurrentIndex(query.value(5).toInt()-1);
        ui->comboBox_18->setCurrentIndex(query.value(6).toInt()-1);
    }

    query.prepare("select wait1,wait2,wait3,wait4,wait5,wait6,wait7 FROM DNA where name=:name");
    query.bindValue(":name",temp);
    query.exec();
    while(query.next())
    {
        ui->lineEdit_4->setText(query.value(0).toString());
        ui->lineEdit_12->setText(query.value(1).toString());
        ui->lineEdit_18->setText(query.value(2).toString());
        ui->lineEdit_24->setText(query.value(3).toString());
        ui->lineEdit_30->setText(query.value(4).toString());
        ui->lineEdit_36->setText(query.value(5).toString());
        ui->lineEdit_42->setText(query.value(6).toString());
    }

    query.prepare("select mix1,mix2,mix3,mix4,mix5,mix6,mix7 FROM DNA where name=:name");
    query.bindValue(":name",temp);
    query.exec();
    while(query.next())
    {
        ui->lineEdit_8->setText(query.value(0).toString());
        ui->lineEdit_13->setText(query.value(1).toString());
        ui->lineEdit_19->setText(query.value(2).toString());
        ui->lineEdit_25->setText(query.value(3).toString());
        ui->lineEdit_31->setText(query.value(4).toString());
        ui->lineEdit_37->setText(query.value(5).toString());
        ui->lineEdit_43->setText(query.value(6).toString());
    }
    query.prepare("select mag1,mag2,mag3,mag4,mag5,mag6,mag7 FROM DNA where name=:name");
    query.bindValue(":name",temp);
    query.exec();
    while(query.next())
    {
        ui->lineEdit_9->setText(query.value(0).toString());
        ui->lineEdit_15->setText(query.value(1).toString());
        ui->lineEdit_21->setText(query.value(2).toString());
        ui->lineEdit_27->setText(query.value(3).toString());
        ui->lineEdit_33->setText(query.value(4).toString());
        ui->lineEdit_39->setText(query.value(5).toString());
        ui->lineEdit_45->setText(query.value(6).toString());
    }
    query.prepare("select vol1,vol2,vol3,vol4,vol5,vol6,vol7 FROM DNA where name=:name");
    query.bindValue(":name",temp);
    query.exec();
    while(query.next())
    {
        ui->lineEdit_10->setText(query.value(0).toString());
        ui->lineEdit_16->setText(query.value(1).toString());
        ui->lineEdit_22->setText(query.value(2).toString());
        ui->lineEdit_28->setText(query.value(3).toString());
        ui->lineEdit_34->setText(query.value(4).toString());
        ui->lineEdit_40->setText(query.value(5).toString());
        ui->lineEdit_46->setText(query.value(6).toString());
    }
    query.prepare("select spd1,spd2,spd3,spd4,spd5,spd6,spd7 FROM DNA where name=:name");
    query.bindValue(":name",temp);
    query.exec();
    while(query.next())
    {
        ui->comboBox_6->setCurrentIndex(query.value(0).toInt()-1);
        ui->comboBox_7->setCurrentIndex(query.value(1).toInt()-1);
        ui->comboBox_9->setCurrentIndex(query.value(2).toInt()-1);
        ui->comboBox_11->setCurrentIndex(query.value(3).toInt()-1);
        ui->comboBox_13->setCurrentIndex(query.value(4).toInt()-1);
        ui->comboBox_15->setCurrentIndex(query.value(5).toInt()-1);
        ui->comboBox_17->setCurrentIndex(query.value(6).toInt()-1);
    }
    query.prepare("select temp1,temp2,temp3,temp4,temp5,temp6,temp7 FROM DNA where name=:name");
    query.bindValue(":name",temp);
    query.exec();
    while(query.next())
    {
        ui->lineEdit_11->setText(query.value(0).toString());
        ui->lineEdit_17->setText(query.value(1).toString());
        ui->lineEdit_23->setText(query.value(2).toString());
        ui->lineEdit_29->setText(query.value(3).toString());
        ui->lineEdit_35->setText(query.value(4).toString());
        ui->lineEdit_41->setText(query.value(5).toString());
        ui->lineEdit_47->setText(query.value(6).toString());
    }
    ui->lineEdit->setText(temp);
    from_edit=1;
    ui->stackedWidget->setCurrentIndex(2);

}
