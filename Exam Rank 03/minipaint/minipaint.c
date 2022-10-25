#include <math.h>
#include <stdio.h>
#include <unistd.h>

int ft_close(FILE *file) {
  write(1, "Error: Operation file corrupted\n", 32);
  fclose(file);
  return 1;
}

int main(int argc, char **argv) {
  FILE *file;
  char c, symb; 
  float x, y, radius, res;
  int i = 0, j = 0, height, width, arg;
 
  if (argc != 2)
    return (write(1, "Error: argument\n", 16) && 1);
  if (!(file = fopen(argv[1], "r")))
    return (write(1, "Error: Operation file corrupted\n", 32) && 1);
  if (fscanf(file, "%d %d %c\n", &width, &height, &symb) != 3)
    return (ft_close(file));
  if (width <= 0 || width > 300 || height <= 0 || height > 300)
    return (ft_close(file));

  char arr[height][width];

  while (i < height) 
  {
    j = 0;
    while (j < width) 
    {
      arr[i][j] = symb;
      j++;
    }
    i++;
  }

  while ((arg = fscanf(file, "%c %f %f %f %c\n", &c, &x, &y, &radius, &symb)) == 5) 
  {
    if ((c != 'c' && c != 'C') || radius <= 0)
      return (ft_close(file));
    i = 0;
    while (i < height) {
      j = 0;
      while (j < width) {
        res = sqrtf(powf(i - y, 2) + powf(j - x, 2));
        if (res <= radius) {
          if ((radius - res < 1 && c == 'c') || c == 'C')
            arr[i][j] = symb;
        }
        j++;
      }
      i++;
    }
  }

  if (arg > 0 && arg != 5)
    return (ft_close(file));
  i = 0;
  while (i < height) 
  {
    j = 0;
    while (j < width)
    {
      write(1, &arr[i][j], 1);
      j++;
    }
    write(1, "\n", 1);
    i++;
  }
  return (fclose(file) && 0);
}