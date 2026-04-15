#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<vector<int>> arrays(n);
        int max_length = 0;
        
        // Leer los arrays
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            arrays[i].resize(k);
            for (int j = 0; j < k; j++) {
                cin >> arrays[i][j];
            }
            max_length = max(max_length, k);
        }
        
        // Crear grilla con -1 para espacios vacíos (asumiendo que los números son positivos)
        vector<vector<int>> grid(n, vector<int>(max_length, -1));
        
        // Llenar la grilla inicial
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < arrays[i].size(); j++) {
                grid[i][j] = arrays[i][j];
            }
        }
        
        // Aplicar gravedad columna por columna
        for (int col = 0; col < max_length; col++) {
            vector<int> column_elements;
            
            // Extraer elementos válidos de esta columna
            for (int row = 0; row < n; row++) {
                if (grid[row][col] != -1) {
                    column_elements.push_back(grid[row][col]);
                    grid[row][col] = -1; // Limpiar la celda
                }
            }
            
            // Colocar elementos en la parte inferior
            int start_row = n - column_elements.size();
            for (int i = 0; i < column_elements.size(); i++) {
                grid[start_row + i][col] = column_elements[i];
            }
        }
        
        // Obtener la fila inferior (solo elementos válidos)
        vector<int> bottom_row;
        for (int col = 0; col < max_length; col++) {
            if (grid[n-1][col] != -1) {
                bottom_row.push_back(grid[n-1][col]);
            }
        }
        
        // Imprimir resultado
        for (int i = 0; i < bottom_row.size(); i++) {
            if (i > 0) cout << " ";
            cout << bottom_row[i];
        }
        cout << "\n";
    }
    
    return 0;
}