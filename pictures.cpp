
char bg[20][41];

void getBackground(char bg[][41]) {
    ifstream fin("pika.txt");
    if (fin) {
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 41; j++)
            {
                bg[i][j] = fin.get();
            }
            fin.ignore();
        }
        fin.close();
    }
    else {
        memset(bg, ' ', sizeof(bg));
    }
}
