#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int count = 0; count < 15; count++) {
        ui->tableWidget->insertRow(count);
    }

    QString ExpressionsForTable[] = {"a/(b-c)*(d+e)", "(a+b)*(c-d)/e",
    "a-(b+c*d)/e", "a/b-((c+d)*e)", "a*(b-c+d)/e", "(a+b)*(c-d)/e",
    "a*(b-c)/(d+e)", "a/(b*(c+d))-e", "(a+(b/c-d))*e", "a*(b+c)/(d-e)",
    "a-(b/c*(d+e))" ,"(a-b)/(c+d)*e", "a/(b+c-d*e)", "a*(b-c)/(d+e)",
    "(a+b*c)/(d-e)"};
    double aForTable[] = {8.6, 7.4, 3.1, 1.2, 9.7, 0.8, 1.6, 8.5, 5.6,
                         0.4, 5.6, 0.3, 7.6, 0.5, 9.1};
    double bForTable[] = {2.4, 3.6, 5.4, 0.7, 8.2, 4.1, 4.9, 0.3, 7.4,
                         2.3, 3.2, 6.7, 4.8, 6.1, 0.6};
    double cForTable[] = {5.1, 2.8, 0.2, 9.3, 3.6, 7.9, 5.7, 2.4, 8.9,
                         6.7, 0.9, 8.4, 3.5, 8.9, 2.4};
    double dForTable[] = {0.3, 9.5, 9.6, 6.5, 4.1, 6.2, 0.8, 7.9, 3.1,
                         5.8, 1.7, 9.5, 9.1, 2.4, 3.7};
    double eForTable[] = {7.9, 0.9, 7.8, 8.4, 0.5, 3.5, 2.3, 1.6, 0.2,
                         9.1, 4.8, 1.2, 0.2, 7.3, 8.5};


    for (int count = 0; count < 15; count++) {
        ui->tableWidget->setItem(count, 0, new QTableWidgetItem(ExpressionsForTable[count]));
        ui->tableWidget->setItem(count, 1, new QTableWidgetItem(QString::number(aForTable[count])));
        ui->tableWidget->setItem(count, 2, new QTableWidgetItem(QString::number(bForTable[count])));
        ui->tableWidget->setItem(count, 3, new QTableWidgetItem(QString::number(cForTable[count])));
        ui->tableWidget->setItem(count, 4, new QTableWidgetItem(QString::number(dForTable[count])));
        ui->tableWidget->setItem(count, 5, new QTableWidgetItem(QString::number(eForTable[count])));
    }

   ui->tableWidget->setEditTriggers(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::Prior(char a)
{
    switch ( a ) {
    case '*': case '/': return 3;

    case '-': case '+': return 2;

    case '(': return 1;
    }
    return 0;

}

bool MainWindow::balanced(std::string s)
{
    Stack<char> stack;
    for (char c : s) {

        switch (c) {

        case '\n': break;
        case '(': {stack.push(')'); break;}

        case ')':
            if (stack.isEmpty() || stack.getTop() != c) {
                return false;
            }
            stack.pop();
            break;
        default:
            break;
        }
    }
    if (stack.isEmpty()) {
        return true;
    } else {
        return false;
    }
}

double MainWindow::doMath(char op, double op1, double op2)
{
    if (op == '*') { return op1 * op2; }
    else if (op == '/') { return op1 / op2; }
    else if (op == '+') { return op1 + op2; }
    else { return op1 - op2; }
}

double MainWindow::postfixEval(std::string postfixExpr, double a, double b, double c, double d, double e)
{
    Stack<double> ops;
    for (unsigned int i = 0; i < postfixExpr.length(); i++) {
        if (postfixExpr[i] >= 'a' && postfixExpr[i] <= 'e') {
            if (postfixExpr[i] == 'a') {
                ops.push(a);
            }
            else if (postfixExpr[i] == 'b') {
                ops.push(b);
            }
            else if (postfixExpr[i] == 'c') {
                ops.push(c);
            }
            else if (postfixExpr[i] == 'd') {
                ops.push(d);
            }
            else if (postfixExpr[i] == 'e') {
                ops.push(e);
            }
        }
        else if (postfixExpr[i] == '*' || postfixExpr[i] == '/' || postfixExpr[i] == '+' || postfixExpr[i] == '-'){
            double op2 = ops.getTop();
            ops.pop();
            double op1 = ops.getTop();
            ops.pop();
            double result = doMath(postfixExpr[i], op1, op2);
            ops.push(result);
        }
    }
    return ops.getTop();
}

std::string MainWindow::RPN(std::string str)
{
    std::string srpn;

    std::string::size_type ind;
    while ((ind = str.find(' ')) != std::string::npos) // удаление пробелов из входной строки
    {
        str.erase(ind, 1);
    }

    for (unsigned int i = 0; i < str.length(); ++i) // учёт отрицательных чисел
    {
        if ((str[i] == '+' || str[i] == '-') && (0 == i || (!isalnum(str[i - 1]) && str[i - 1] != '.' && str[i - 1] != ')')))
        {
            auto it = std::find_if(str.begin() + i + 1, str.end(), [](char const c) {return !isalnum(c); });
            str.insert(it, ')');
            str.insert(i, "(0");
        }
    }

    Stack<char> stack;

    for (auto c : str) // формировка результирующей строки в ОПЗ
    {
        if (!isalnum(c) && ('.' != c))
        {
            if (')' == c)
            {
                while (stack.getTop() != '(')
                {
                    srpn += stack.getTop();
                    stack.pop();
                }
                stack.pop();
            }
            else if ('(' == c)
            {
                stack.push(c);
            }
            else if (stack.isEmpty() || (Prior(stack.getTop()) < Prior(c)))
            {
                stack.push(c);
            }
            else
            {
                do
                {
                    srpn += stack.getTop();
                    stack.pop();
                } while (!(stack.isEmpty() || (Prior(stack.getTop()) < Prior(c))));
                stack.push(c);
            }
        }
        else
        {
            srpn += c;
        }
    }
    while (!stack.isEmpty())// остаток из стека добавляется в результ. строку
    {
        srpn += stack.getTop();
        stack.pop();
    }
    return srpn;
}


void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();

    std::string strIn = (ui->CalcLE->text()).toStdString();

    for (char c : strIn) {
        if (c != 'a' && c != 'b' && c != 'c' && c != 'd' && c != 'e' && c != '(' && c!= ')' && c!= '+' && c!= '-' && c!= '*' && c!= '/'){
            QMessageBox::warning(this, "Error", "Incorrect Input!");
            return;
        }
    }

    if (!balanced(strIn)) {
        QMessageBox::warning(this, "Error", "Incorrect input! Check brackets");
        return;
    }

    if (ui->aLE->text() == '\0' || ui->bLE->text() == '\0' || ui->cLE->text() == '\0' || ui->dLE->text() == '\0' || ui->eLE->text() == '\0') {
        QMessageBox::critical(this, "Error!", "Fill all the fields for numbers!");
        return;
    }
    std::string strPol = RPN((ui->CalcLE->text()).toStdString());
    ui->textEdit->insertPlainText(QString::fromStdString(strPol));
    double a = QString(ui->aLE->text()).toDouble();
    double b = QString(ui->bLE->text()).toDouble();
    double c = QString(ui->cLE->text()).toDouble();
    double e = QString(ui->eLE->text()).toDouble();
    double d = QString(ui->dLE->text()).toDouble();
    double answer = postfixEval(strPol, a, b, c, d ,e);
    ui->textEdit_2->insertPlainText(QString::number(answer));
}


void MainWindow::on_polishFormBtn_clicked()
{
    for (int count = 0; count < 15; count++) {
        std::string strPol = RPN((ui->tableWidget->item(count,0)->text()).toStdString());
        ui->tableWidget->setItem(count, 6, new QTableWidgetItem(QString::fromStdString(strPol)));
    }
}


void MainWindow::on_getResultBtn_clicked()
{
    for (int count = 0; count < 15; count++) {
        double a = QString(ui->tableWidget->item(count,1)->text()).toDouble();
        double b = QString(ui->tableWidget->item(count,2)->text()).toDouble();
        double c = QString(ui->tableWidget->item(count,3)->text()).toDouble();
        double d = QString(ui->tableWidget->item(count,4)->text()).toDouble();
        double e = QString(ui->tableWidget->item(count,5)->text()).toDouble();
        std::string strPol = RPN((ui->tableWidget->item(count,0)->text()).toStdString());
        double answer = postfixEval(strPol, a, b, c, d ,e);
        ui->tableWidget->setItem(count, 7, new QTableWidgetItem(QString::number(answer)));
    }
}

