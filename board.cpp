#include "mylib.cpp"
#include "pictures.cpp"

// ===================================== KHAI BAO CAC BIEN =====================================
int n_rows = 8, n_cols = 8, n_types = 26;
vector<int> countAlphabets = {2, 4, 2, 2, 8, 2, 2, 4, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4};

char** pokemons = new char*[n_rows];
// ===================================== KHAI BAO CAC HAM ======================================
void addPokemon(int x, int y, char type, char** pokemons);
char getPokemon(int x, int y, char** pokemons);
void removePokemon(int x, int y, char** pokemons);
void Board(int n_rows, int n_cols, int n_types, vector<int> countAlphabets, char** pokemons);

void TextColor(int x);
void input2DArr(char** pokemons);
void freedom2DArr(char** pokemons);
void print(char **c, int n);
//===============================================================================================

// thêm pokemon thuộc loại type vào ô ở hàng x cột y
void addPokemon(int x, int y, char type, char** pokemons) {
    pokemons[x][y] = type;
}

// trả về loại pokemon ở ô hàng x cột y
char getPokemon(int x, int y, char** pokemons) {
    return pokemons[x][y];
}

// xóa pokemon ở ô hàng x cột y (gán loại pokemon ở ô này = x). 
void removePokemon(int x, int y, char** pokemons) {
    pokemons[x][y] = '0';
}

void Board(int n_rows, int n_cols, int n_types, vector<int> countAlphabets, char** pokemons) {
    map<char, int> countType; // counts the number of type x
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            char type;
            do {
                type = 'A' + rand() % n_types; // n_types: so loai pokemon khac nhau
            } while (countType[type] == countAlphabets[type - 'A']);
            countType[type] += 1;
            addPokemon(i, j, type, pokemons);            
        }
    }
}

void input2DArr(char** pokemons) {
	for (int i = 0; i < n_rows; i++) {
		pokemons[i] = new char[n_cols];
	}
} 

void freedom2DArr(char** pokemons) {
	for (int i = 0; i < n_rows; i++) {
		delete[] pokemons[i];
	}
	delete[] pokemons;
	pokemons = NULL;
}

void printGirdOfPokemons(char**c, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << " ";
        int j;
        for (j = 0; j < n; j++)
        {
            if (c[i][j] != '0')
            {
                cout << "----";
            }
            else
            {
                if (i == 0 || c[i - 1][j] == '0')
                    cout << "    ";
                else
                    cout << "----";
            }
        }
        cout << "\n";
        if (c[i][0] == '0')
            cout << "    ";
        else
        {
            cout << " | ";       	
	        cout << c[i][0];
        }
        for (j = 1; j < n; j++)
        {
            if (c[i][j] == '0')
            {
                if (c[i][j - 1] != '0')
                    cout << " |  ";
                else
                    cout << "    ";
            }
            else
            {
                if (c[i][j - 1] == '0')
                    cout << " | ";
                else
                    cout << " | ";
                cout << c[i][j];
            }
        }
        if (c[i][j - 1] != '0')
            cout << " |\n";
        else
            cout << " \n";
    }
    cout << " ";
    for (int j = 0; j < n; j++)
    {
        if (c[i - 1][j] != '0')
            cout << "----";
        else
            cout << "    ";
    }
}

bool checkEmptyBoard(char** pokemons) {
	for (int i = 0; i < n_rows; i++) {
		for (int j = 0; j < n_cols; j++) {
			if (pokemons[i][j] != '0')
				return false;
		}
	}
	return true;
}

//int main() {
//	input2DArr(pokemons);
//	
//    Board(n_rows, n_cols, n_types, countAlphabets, pokemons);
//    
//    printGirdOfPokemons(pokemons, n_rows);
//    
//    return 0;
//}
