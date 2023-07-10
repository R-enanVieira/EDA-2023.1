void ordena (int *v, int n) {
  if (n <= 1) return;

  int i, minIndex = 0;
  for (i = 1; i < n; i++) {
      if (v[i] < v[minIndex]) {
          minIndex = i;
      }
  }
  int aux = v[0];
  v[0] = v[minIndex];
  v[minIndex] = aux;
  ordena(v + 1, n - 1);
}
