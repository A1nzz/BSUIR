#include "Task3Visual.h"

Task3Visual::Task3Visual(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.lineEdit->setInputMask("99999");
}

Vector<char> Task3Visual::powstr(Vector<char>& str, int k) {
    Vector<char> deg;

    deg.push_back('1');

    if (k == 0)
    {
        deg.push_back('q');
        return(deg);
    }

    for (int i = 0; i < k; i++)
    {
        deg.push_back('0');
    }

    for (int i = deg.size() - 1, j = len(str) - 1; i >= 0 && j >= 0; i--, j--)
    {
        deg[i] = str[j];
    }

    deg.push_back('q');
    return(deg);
}
int Task3Visual::len(Vector<char>& a) {
    int len = 0;

    for (; a[len] != 'q'; len++);

    return(len);
}
bool Task3Visual::k_bit(Vector<char> str1, int k) {
    Vector<char> str = str1;
    int bit, i = 0;
    int lenstr = len(str);

    for (; i != k; i++)
    {
        bit = (str[lenstr - 1] - '0') % 2;
        str[lenstr - 1] = str[lenstr - 1] - bit;

        for (int j = lenstr - 1; j >= 0; j--)
        {
            if ((str[j] - '0') % 2 == 0)
            {
                str[j] = (str[j] - '0') / 2 + '0';
            }
            else
            {
                str[j] = (str[j] - '0') / 2 + '0';

                if (j != lenstr - 1)
                {
                    str[j + 1] = str[j + 1] + 5;
                }
            }
        }
    }

    return(bit);
}

void Task3Visual::on_pushButton_clicked() {
    if (ui.lineEdit->text().toInt() < 1 || ui.lineEdit->text().toInt() > 10000) {
        QMessageBox::warning(this, "Fail", "Incorrect n!");
        return;
    }
    int n = ui.lineEdit->text().toInt();

    Vector<Vector<char>> A;
    Vector<char> temp;
    A.resize(10000, temp);
    Vector<Vector<char>> B;
    B.resize(10000, temp);

    for (int i = 0; i < 10000; i++)
    {
        A[i].resize(200, 'q');
        B[i].resize(200, 'q');
    }

    A[0][0] = '0';

    int counterB, counterA = 1, k = 1, counterBIN = 1, tmp;

    while (n >= counterBIN)
    {
        tmp = counterB = 0;

        for (int i = 0; i < counterA; i++)
        {
            if (!k_bit(A[i], k))
            {
                A[tmp] = A[i];
                tmp++;
            }
        }

        counterA = tmp;

        for (int i = 0; i < counterA; i++)
        {
            B[i] = powstr(A[i], k - 1);
            counterB++;
        }

        for (int i = 0; i < counterB; i++)
        {
            A[counterA] = B[i];
            counterA++;
        }

        counterBIN += counterB;
        k++;
    }
    QString string = "";
    QString str;
    for (int i = 0; i < B[counterB - (counterBIN - n)].size(); i++)
    {
        if (B[counterB - (counterBIN - n)][i] == 'q')
        {
            break;
        }
        QString str = QString(QChar::fromLatin1(B[counterB - (counterBIN - n)][i]));
        string += str;
    }
    ui.plainTextEdit->appendPlainText(string);
}