#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pila.h"

int cont = 0;
 int prec;
QString resultado;
Pila* pila = new Pila();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void Evaluar(char car){

if(car == '^'){
    prec = 3;
}else if(car == '*' || car == '/' ){
    prec = 2;
}else if(car == '+' || car == '-'){
    prec = 1;
}else{
    prec = 0;
}
cout << "entra car "<< car << " prec " << prec << endl;
if(pila->vacia()){

    pila->add(new NodoPila(car, prec));
    pila->recorrer();

} else if(car == ')' ){

    cout << "valores antes de insertar el de menor" << pila->valores().toStdString().c_str() << endl;
    resultado.append(pila->valores());
    pila->clear();
   // pila->recorrer();

} else if(pila->peek()->prec == prec ){

    char d1 = pila->peek()->val;
    int d2 = pila->peek()->prec;
    cout << "invertido 1 " << d1 << d2 << " invertido2 " << car<<prec<< endl;
    pila->get();

    pila->add(new NodoPila(d1, d2));
    pila->add(new NodoPila(car, prec));
    pila->recorrer();

} else if ( prec > pila->peek()->prec){

    pila->add(new NodoPila(car, prec));
    pila->recorrer();

} else if ( prec < pila->peek()->prec ){

    resultado.append(pila->valores());
    cout << "valores antes de insertar el de menor" << pila->valores().toStdString().c_str() << endl;
    pila->clear();
    pila->add(new NodoPila(car, prec));
    pila->recorrer();

}
}


void InfijaAPostFija(QString cad){

    QByteArray ba = cad.toLatin1();
    const char *Arreglo = ba.data();

    int tam = strlen(Arreglo);

    cout << Arreglo << " tamaño "<< tam <<endl;

while(cont < tam){

 if(Arreglo[cont] == '^' || Arreglo[cont] == '*' || Arreglo[cont] == '/' ||
    Arreglo[cont] == '+' || Arreglo[cont] == '-' || Arreglo[cont] == '(' ||
    Arreglo[cont] == ')' ) {

    Evaluar(Arreglo[cont]);

} else {

    resultado.append(Arreglo[cont]);
    resultado = resultado + ",";

}
cont++;
}

resultado.append(pila->valores());

pila->clear();

}

void MainWindow::on_btnpasar_clicked()
{

    InfijaAPostFija(ui->txtentrada->text());
    cout<<"entrada " << ui->txtentrada->text().toStdString().c_str() << endl;
    ui->txtresultado->setText(resultado);
    cout <<"resultado "<< resultado.toStdString().c_str() << endl;

    ui->txtentrada->setText("");

    resultado = resultado + "\n";
    pila->clear();

}
