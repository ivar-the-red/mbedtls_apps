#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"


int main (int argc, char** argv)
{
    mbedtls_entropy_context entropy;
    mbedtls_entropy_init(&entropy);

    mbedtls_ctr_drbg_context ctr_drbg;
    char *personalization = "my_app_specific_string";

    mbedtls_ctr_drbg_init( &ctr_drbg );

    int ret = mbedtls_ctr_drbg_seed( &ctr_drbg , mbedtls_entropy_func, &entropy,
                     (const unsigned char *) personalization,
                     strlen( personalization ) );
    if( ret != 0 )
    {
        printf("The ret was not zero!\n");
    }

    return EXIT_SUCCESS;
}