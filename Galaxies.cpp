#include <iostream>
#include <ctime>
#include <Windows.h>


using namespace std;

bool NextTo1(int r, int p, int size)
{
    if (r >= p)
        r -= p;
    else
    {
        r -= p;
        r = -r;
    }

    if ((r <= 1) || ((r <= size + 1) & (r >= size - 1)))
        return true;
    else
        return false;
}

bool NextTo2(int r, int p, int size)
{
    if (r >= p)
        r -= p;
    else
    {
        r -= p;
        r = -r;
    }
    if ((r <= 1) || ((r <= size + 1) & (r >= size - 1)) || ((r <= size * 2 + 1) & (r >= size * 2 - 1)))
        return true;
    else
        return false;
}

bool NextTo3(int r, int p, int size)
{
    if (r >= p)
        r -= p;
    else
    {
        r -= p;
        r = -r;
    }
    if ((r <= 2) || ((r <= size + 2) & (r >= size - 2)))
        return true;
    else
        return false;
}


bool NextTo4(int r, int p, int size)
{
    if (r >= p)
        r -= p;
    else
    {
        r -= p;
        r = -r;
    }
    if ((r <= 2) || ((r <= size + 2) & (r >= size - 2)) || ((r <= size * 2 + 2) & (r >= size * 2 - 2)))
        return true;
    else
        return false;
}

void poisk(int x, char** t, int size1, int size2, int k)
{
    int i = 0, countofkletka, movex, movey, posx = x, posy = 0;
    COORD temp,* kletka = new COORD[size1 * size2];
    while (posx >= size2)
    {
        posx -= size2;
        posy++;
    }
    if (((x % size2) % 2 == 1) & ((x / size2) % 2 == 1))
    {
        countofkletka = 1;
        kletka[i].X = posx;
        kletka[i].Y = posy;
    }
    else if (((x % size2) % 2 == 0) & ((x / size2) % 2 == 1))
    {
        countofkletka = 2;
        kletka[i].X = posx + 1;
        kletka[i].Y = posy;
        kletka[i + 1].X = posx - 1;
        kletka[i + 1].Y = posy;
    }
    else if (((x % size2) % 2 == 1) & ((x / size2) % 2 == 0))
    {
        countofkletka = 2;
        kletka[i].X = posx;
        kletka[i].Y = posy + 1;
        kletka[i + 1].X = posx;
        kletka[i + 1].Y = posy - 1;
    }
    else
    {
        countofkletka = 4;
        kletka[i].X = posx + 1;
        kletka[i].Y = posy - 1;
        kletka[i + 1].X = posx + 1;
        kletka[i + 1].Y = posy + 1;
        kletka[i + 2].X = posx - 1;
        kletka[i + 2].Y = posy + 1;
        kletka[i + 3].X = posx - 1;
        kletka[i + 3].Y = posy - 1;
    }

    while (i < countofkletka)
    {
        movex = kletka[i].X - posx;
        movey = kletka[i].Y - posy;
        if ((kletka[i].X != size2 - 2) & (posx - movex - 2 > 0))
        {
            if (t[kletka[i].Y][kletka[i].X + 2] == ' ')
            {
                if (t[posy - movey][posx - movex - 2] == ' ')
                {
                    t[kletka[i].Y][kletka[i].X + 2] = t[posy - movey][posx - movex - 2] = (char)(((int)'0') + k);
                    kletka[countofkletka].Y = kletka[i].Y;
                    kletka[countofkletka].X = kletka[i].X + 2;
                    kletka[countofkletka + 1].Y = posy - movey;
                    kletka[countofkletka + 1].X = posx - movex - 2;
                    countofkletka += 2;
                }
            }
        }

        if ((kletka[i].Y < size1 - 2) & (posy - movey - 2 > 0)) 
        {
            if (t[kletka[i].Y + 2][kletka[i].X] == ' ')
            {
                if (t[posy - movey - 2][posx - movex] == ' ')
                {
                    t[kletka[i].Y + 2][kletka[i].X] = t[posy - movey - 2][posx - movex] = (char)(((int)'0') + k);
                    kletka[countofkletka].Y = kletka[i].Y + 2;
                    kletka[countofkletka].X = kletka[i].X;
                    kletka[countofkletka + 1].Y = posy - movey - 2;
                    kletka[countofkletka + 1].X = posx - movex;
                    countofkletka += 2;
                }
            }
        }

        if ((kletka[i].X != 1) & (posy - movex + 2 < size2))
        {
            if (t[kletka[i].Y][kletka[i].X - 2] == ' ')
            {
                if (t[posy - movey][posx - movex + 2] == ' ')
                {
                    t[kletka[i].Y][kletka[i].X - 2] = t[posy - movey][posx - movex + 2] = (char)(((int)'0') + k);
                    kletka[countofkletka].Y = kletka[i].Y;
                    kletka[countofkletka ].X = kletka[i].X - 2;
                    kletka[countofkletka + 1].Y = posy - movey;
                    kletka[countofkletka + 1].X = posx - movex + 2;
                    countofkletka += 2;
                }
            }
        }

        if ((kletka[i].Y > 1)&(posy - movey + 2 < size1))
        {
            if (t[kletka[i].Y - 2][kletka[i].X] == ' ')
            {
                if (t[posy - movey + 2][posx - movex] == ' ')
                {
                    t[kletka[i].Y - 2][kletka[i].X] = t[posy - movey + 2][posx - movex] = (char)(((int)'0') + k);
                    kletka[countofkletka].Y = kletka[i].Y - 2;
                    kletka[countofkletka].X = kletka[i].X;
                    kletka[countofkletka + 1].Y = posy - movey + 2;
                    kletka[countofkletka + 1].X = posx - movex;
                    countofkletka += 2;
                }
            }
        }

        i++;
    }
}


int main()
{
    setlocale(LC_ALL, "");

    int n, m;
    cout << "Введите количество строк: ";
    cin >> n;
    cout << "Введите количество столбцов: ";
    cin >> m;
    n = n * 2 + 1;
    m = m * 2 + 1;
    char** tabl = new char* [n];
    for (int i = 0; i < n; i++)
    {
        tabl[i] = new char[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i % 2 == 0)
                if (j % 2 == 0)
                    tabl[i][j] = '+';
                else
                    tabl[i][j] = '-';
            else
            {
                if (j % 2 == 0)
                    tabl[i][j] = '|';
                else
                    tabl[i][j] = ' ';
            }
        }
    }

    int t, test = 0, rnd, count = 0;
    bool f = 1;
    srand(time(0));
    t = rand() % (((m - 1) / 2) * ((n - 1) / 2))/4;
    if (t < (((m - 1) / 2) * ((n - 1) / 2)) / 8)
        t += (((m - 1) / 2) * ((n - 1) / 2)) / 8;
    int g = 0;
    int* pos = new int[t];
    srand(time(0));
    while (g < t)
    {
        rnd = rand() % ((n - 1) * m);
        if ((rnd + 1) < m)
            rnd += m;
        if ((rnd + 1) % m == 0)
            rnd -= 1;
        if ((rnd + 1) % m == 1)
            rnd += 1;
        for (int j = 0; j < g; j++)
        {
            if (((pos[j] % m) % 2 == 1) & ((pos[j] / m) % 2 == 1))
            {
                if (NextTo1(pos[j], rnd, m))
                {
                    f = 0;
                    break;
                }
            }
            else if (((pos[j] % m) % 2 == 1) & ((pos[j] / m) % 2 == 0))
            {
                if (NextTo2(pos[j], rnd, m))
                {
                    f = 0;
                    break;
                }
            }
            else if (((pos[j] % m) % 2 == 0) & ((pos[j] / m) % 2 == 1))
            {
                if (NextTo3(pos[j], rnd, m))
                {
                    f = 0;
                    break;
                }
            }
            else if (((pos[j] % m) % 2 == 0) & ((pos[j] / m) % 2 == 0))
            {
                if (NextTo4(pos[j], rnd, m))
                {
                    f = 0;
                    break;
                }
            }
        }
        if (f)
        {
            pos[g] = rnd;
            int temp = rnd;
            count = 0;
            while (temp >= m)
            {
                temp -= m;
                count++;
            }
            if (((pos[g] % m) % 2 == 1) & ((pos[g] / m) % 2 == 0))
            {
                tabl[count - 1][temp] = tabl[count + 1][temp] = (char)(((int)'0') + g);
            }
            else if (((pos[g] % m) % 2 == 0) & ((pos[g] / m) % 2 == 1))
            {
                tabl[count][temp - 1] = tabl[count][temp + 1] = (char)(((int)'0') + g);
            }
            else if (((pos[g] % m) % 2 == 0) & ((pos[g] / m) % 2 == 0))
            {
                tabl[count - 1][temp - 1] = tabl[count - 1][temp + 1] = tabl[count + 1][temp - 1] = tabl[count + 1][temp + 1] = (char)(((int)'0') + g);
            }

            g++;
        }
        f = 1;
    }
    cout << endl;
    
    for (int i = 0; i < t; i++)
    {
        int temp = pos[i];
        count = 0;
        while (temp >= m)
        {
            temp -= m;
            count++;
        }
        tabl[count][temp] = '*';
        count = 0;
    }
    cout << endl;

    int simbol;
    for (simbol = 0; simbol < t; simbol++)
    {
            poisk(pos[simbol], tabl, n, m, simbol);
    }
    simbol++;

    int* pusto = new int[n * m];
    f = 1;
    while (f) 
    {
        f = 0;
        count = 0;
        for (int i = 0; i < (n - 1) / 2; i++)
        {
            for (int j = 0; j < (m - 1) / 2; j++)
            {
                if (tabl[2 * i + 1][2 * j + 1] == ' ')
                {
                    pusto[count] = ((2 * i + 1) * m) + 2 * j + 1;
                    count++;
                    f = 1;
                }
            }
        }
        if (f)
        {
            srand(time(0));
            if (count > 0)
                rnd = rand() % count;
            else
                rnd = 0;
            int temp = pusto[rnd];
            count = 0;
            while (temp >= m)
            {
                temp -= m;
                count++;
            }

            if ((temp < m - 2) & (temp > 1))
            {
                if ((tabl[count][temp + 2] == ' ') & (tabl[count][temp - 2] != ' '))
                {
                    tabl[count][temp + 1] = '*';
                    pusto[rnd] += 1;
                }
                else if ((tabl[count][temp - 2] == ' ') & (tabl[count][temp + 2] != ' '))
                {
                    tabl[count][temp - 1] = '*';
                    pusto[rnd] -= 1;
                }
                else
                    tabl[count][temp] = '*';
            }
            else if ((count < n - 2) & (count > 1))
            {
                if ((tabl[count + 2][temp] == ' ') & (tabl[count - 2][temp] != ' '))
                {
                    tabl[count + 1][temp] = '*';
                    pusto[rnd] += m;
                }
                else if ((tabl[count - 2][temp] == ' ') & (tabl[count + 2][temp + 2] != ' '))
                {
                    tabl[count - 1][temp] = '*';
                    pusto[rnd] -= m;
                }
                else
                    tabl[count][temp] = '*';
            }
            else
                tabl[count][temp] = '*';
            poisk(pusto[rnd], tabl, n, m, simbol++);
        }
    }

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tabl[i][j] == '*')
            {
                SetConsoleTextAttribute(h, 3);
                cout << tabl[i][j] << " ";
                SetConsoleTextAttribute(h, 15);

            }
            else if (((i % 2 != 1) || (j % 2 != 1)) & ((tabl[i][j] == '|') || ((tabl[i][j] == '-') || (tabl[i][j] == '+'))))
            {
                cout << tabl[i][j] << " ";
            }
            else
                cout << ' ' << " ";
        }
        cout << endl;
    }


    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tabl[i][j] == '*')
            {
                SetConsoleTextAttribute(h, 3);
                cout << tabl[i][j] << " ";
                SetConsoleTextAttribute(h, 15);

            }
            else
            {
                cout << tabl[i][j] << " ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] tabl[i];
    }
    delete[] pos;
    delete[] pusto;
}
