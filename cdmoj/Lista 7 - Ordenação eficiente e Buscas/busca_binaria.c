#include <stdio.h>

int binary_search(int *v, int l, int r, int key) {
  if(l > r) return -1;
  int m = (l+r)/2;
  if(m == 0) {
   if(key <= v[m]) return m;
   else if(key <=v[m+1]) return m+1;
  }
  if(key > v[m-1] && key <= v[m]) return m;
  if(key > v[m]) return binary_search(v, m+1, r, key);  
  return binary_search(v, l, m-1, key);
}

int main() {                                      
  int n,m;
  scanf("%d %d", &n, &m);
  int vect[n], vect2[m];
  for(int i = 0; i < n; i++) {
    scanf("%d", &vect[i]);
  }
  for(int i = 0; i < m; i++) {
    scanf("%d", &vect2[i]);
  }
  for(int i = 0; i < m; i++) {
    int aux = binary_search(vect,0, n-1, vect2[i]);
    if(aux != -1)
      printf("%d\n", binary_search(vect, 0, n-1, vect2[i]));
    else
      printf("%d\n", n);
  }
  
  return 0;
}
