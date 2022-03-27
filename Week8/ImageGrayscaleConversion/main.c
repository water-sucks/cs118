#include <stdio.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>

extern void make_grayscale(uint8_t *image, size_t image_size, uint8_t *output,
                           size_t output_size);

int main(int argc, char **args) {
  if (argc < 2) {
    fprintf(stderr, "Error: no source file provided\n");
    return 1;
  }
  char *out = NULL;
  if (argc < 3) {
    out = malloc(10 + strlen(args[1]) + 1);
    strcpy(out, "grayscale-");
    strcat(out, args[1]);
    printf("No destination provided, defaulting to ./%s\n", out);
  } else {
    out = args[2];
  }

  int width, height, channels;
  uint8_t *original_image = stbi_load(args[1], &width, &height, &channels, 3);
  if (original_image == NULL) {
    printf("Error in loading image\n");
    return 1;
  }

  size_t original_size = width * height * channels;
  size_t gray_size = width * height;
  uint8_t *grayscale_image = (uint8_t(*))malloc(gray_size);

  // Assembly function
  make_grayscale(original_image, original_size, grayscale_image, gray_size);
  // C version
  // for (uint8_t *i = original_image, *j = grayscale_image;
  //      i != original_image + original_size; i += channels, j++) {
  //   *j = (uint8_t)((*i + *(i + 1) + *(i + 2)) / 3);
  // }

  stbi_write_jpg(out, width, height, 1, grayscale_image, 100);

  free(grayscale_image);

  stbi_image_free(original_image);

  return 0;
}
