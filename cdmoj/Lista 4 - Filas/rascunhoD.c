if (f->p > f->u) {
      //laço que percorre do primeiro da fila elemto até o fim do vetor
      while(i < f->N/2) {
        novo[cont] = f->dados[i];
        cont++;
        i++;
      }
      //laço que percorre do primeiro elemento do vetor até o último elemento da fila
      i = 0;
      while(i < f->u) {
        novo[cont] = f->dados[i];
        i++;
        cont++;
      }
   }else{
    for (int i = f->p; i < f->u; i++) {
      novo[cont] = f->dados[i];
      cont++;
  }

free (f->dados);
    f->dados = novo;
    f->p = 0;
    f->u = cont;
    /*f->N *= 2;
    f->dados = realloc(f->dados, f->N * sizeof (int));*/

