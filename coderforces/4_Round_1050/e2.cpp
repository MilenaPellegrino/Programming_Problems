#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n);
        map<int, int> total_freq;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total_freq[a[i]]++;
        }
        
        // Verificación inicial: para que CUALQUIER subarreglo pueda ser awesome,
        // cada valor debe aparecer al menos k veces en total
        bool possible = true;
        for (auto& pair : total_freq) {
            if (pair.second < k) {
                possible = false;
                break;
            }
        }
        
        if (!possible) {
            cout << 0 << "\n";
            continue;
        }
        
        long long awesome_count = 0;
        
        // Enfoque optimizado: para cada punto inicial l
        for (int l = 0; l < n; l++) {
            map<int, int> freq_inside;  // frecuencias dentro del subarreglo actual
            map<int, int> freq_outside; // frecuencias fuera del subarreglo actual
            
            // Inicializar freq_outside con todas las frecuencias
            freq_outside = total_freq;
            
            // Para cada punto final r >= l
            for (int r = l; r < n; r++) {
                // Agregar a[r] al subarreglo
                freq_inside[a[r]]++;
                freq_outside[a[r]]--;
                
                // Verificar si el subarreglo [l, r] es awesome
                bool is_awesome = true;
                
                // Verificar cada valor que aparece dentro del subarreglo
                for (auto& pair : freq_inside) {
                    int value = pair.first;
                    int count_inside = pair.second;
                    int count_outside = freq_outside[value];
                    
                    // Necesitamos count_inside * (k-1) elementos fuera
                    if (count_outside < count_inside * (k - 1)) {
                        is_awesome = false;
                        break;
                    }
                }
                
                if (is_awesome) {
                    // Verificar valores que solo aparecen fuera
                    for (auto& pair : freq_outside) {
                        int value = pair.first;
                        int count_outside = pair.second;
                        
                        if (count_outside > 0 && freq_inside[value] == 0) {
                            // Este valor no está en el subarreglo pero sí fuera
                            // Debe ser divisible por k para distribuir equitativamente
                            if (count_outside % k != 0) {
                                is_awesome = false;
                                break;
                            }
                        }
                    }
                }
                
                if (is_awesome) {
                    awesome_count++;
                }
            }
        }
        
        cout << awesome_count << "\n";
    }
    
    return 0;
}