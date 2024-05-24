#include <openssl/evp.h>
#include "../inc/advent.h"

// Función para calcular el hash MD5 usando la API EVP
void calculate_md5(const char *str, char *md5_result) {
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();  // Crear el contexto
    if (ctx == NULL) {
        perror("Error al crear el contexto EVP_MD_CTX");
        exit(EXIT_FAILURE);
    }

    // Inicializar el contexto para usar MD5
    if (EVP_DigestInit_ex(ctx, EVP_md5(), NULL) != 1) {
        perror("Error al inicializar el contexto MD5");
        EVP_MD_CTX_free(ctx);
        exit(EXIT_FAILURE);
    }

    // Actualizar el contexto con los datos
    if (EVP_DigestUpdate(ctx, str, strlen(str)) != 1) {
        perror("Error al actualizar el contexto MD5");
        EVP_MD_CTX_free(ctx);
        exit(EXIT_FAILURE);
    }

    // Obtener el hash final
    unsigned char digest[EVP_MD_size(EVP_md5())];
    unsigned int digest_len;
    if (EVP_DigestFinal_ex(ctx, digest, &digest_len) != 1) {
        perror("Error al obtener el hash MD5");
        EVP_MD_CTX_free(ctx);
        exit(EXIT_FAILURE);
    }

    // Convertir el hash a una cadena hexadecimal
    for (unsigned int i = 0; i < digest_len; i++) {
        sprintf(&md5_result[i * 2], "%02x", (unsigned int)digest[i]);
    }

    EVP_MD_CTX_free(ctx);  // Liberar el contexto
}