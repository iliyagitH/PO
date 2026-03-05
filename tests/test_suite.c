#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "cblas.h"

void report(const char* name, int condition) {
    if (condition) printf("Test %-15s: [ PASSED ]\n", name);
    else printf("Test %-15s: [ FAILED ]\n", name);
}

int main() {
    printf("=== RUNNING 25 VALIDATION TESTS ===\n");

    double dA[4] = {1,2,3,4}, dx[2] = {1,1}, dy[2] = {1,1};
    double complex zA[4] = {1+I, 2+I, 3+I, 4+I}, zx[2] = {1+I, 1+I}, zy[2] = {0,0};
    double complex zalpha = 1.0 + 0.0*I, zbeta = 0.0 + 0.0*I;
    double dAp[3] = {1, 2, 3}, dAband[6] = {0, 1, 2, 3, 4, 5};
    double complex zAp[3] = {1+I, 2+I, 3+I};

    dy[0] = 0; cblas_dgemv(CblasRowMajor, CblasNoTrans, 2, 2, 1.0, dA, 2, dx, 1, 0.0, dy, 1);
    report("DGEMV", dy[0] != 0);

    zy[0] = 0; cblas_zhemv(CblasRowMajor, CblasUpper, 2, &zalpha, zA, 2, zx, 1, &zbeta, zy, 1);
    report("ZHEMV", creal(zy[0]) != 0);

    dy[0] = 0; cblas_dsymv(CblasRowMajor, CblasUpper, 2, 1.0, dA, 2, dx, 1, 0.0, dy, 1);
    report("DSYMV", dy[0] != 0);

    dx[0] = 1.0; dx[1] = 1.0;
    cblas_dtrmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 2, dA, 2, dx, 1);
    report("DTRMV", dx[0] != 1.0 || dx[1] != 1.0);

    dx[0] = 1.0; dx[1] = 1.0;
    cblas_dtrsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 2, dA, 2, dx, 1);
    report("DTRSV", dx[0] != 1.0 || dx[1] != 1.0);

    double dAg[4] = {0,0,0,0};
    cblas_dger(CblasRowMajor, 2, 2, 1.0, dx, 1, dy, 1, dAg, 2);
    report("DGER", dAg[0] != 0.0);

    double complex zAg_u[4] = {0,0,0,0};
    double complex zx_u[2] = {2.0 + 2.0*I, 2.0 + 2.0*I};
    cblas_zgeru(CblasRowMajor, 2, 2, &zalpha, zx_u, 1, zx_u, 1, zAg_u, 2);
    report("ZGERU", creal(zAg_u[0]) != 0.0 || cimag(zAg_u[0]) != 0.0);

    double complex zAc[4] = {0,0,0,0};
    cblas_zgerc(CblasRowMajor, 2, 2, &zalpha, zx, 1, zx, 1, zAc, 2);
    report("ZGERC", creal(zAc[0]) != 0.0);

    dA[0] = 10.0; cblas_dsyr(CblasRowMajor, CblasUpper, 2, 1.0, dx, 1, dA, 2);
    report("DSYR", dA[0] != 10.0);

    zA[0] = 10.0 + 0*I; double dalpha = 1.0;
    cblas_zher(CblasRowMajor, CblasUpper, 2, dalpha, zx, 1, zA, 2);
    report("ZHER", creal(zA[0]) != 10.0);

    dA[0] = 10.0; cblas_dsyr2(CblasRowMajor, CblasUpper, 2, 1.0, dx, 1, dy, 1, dA, 2);
    report("DSYR2", dA[0] != 10.0);

    zA[0] = 10.0 + 0*I;
    cblas_zher2(CblasRowMajor, CblasUpper, 2, &zalpha, zx, 1, zy, 1, zA, 2);
    report("ZHER2", creal(zA[0]) != 10.0);
    
    dy[0] = 0; cblas_dgbmv(CblasRowMajor, CblasNoTrans, 2, 2, 1, 1, 1.0, dAband, 3, dx, 1, 0.0, dy, 1);
    report("DGBMV", dy[0] != 0);

    zy[0] = 0; cblas_zhbmv(CblasRowMajor, CblasUpper, 2, 1, &zalpha, zA, 2, zx, 1, &zbeta, zy, 1);
    report("ZHBMV", creal(zy[0]) != 0);

    dy[0] = 0; cblas_dsbmv(CblasRowMajor, CblasUpper, 2, 1, 1.0, dAband, 2, dx, 1, 0.0, dy, 1);
    report("DSBMV", dy[0] != 0);

    dx[0] = 1.0; cblas_dtbmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 2, 1, dAband, 2, dx, 1);
    report("DTBMV", dx[0] != 1.0);

    dx[0] = 1.0; cblas_dtbsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 2, 1, dAband, 2, dx, 1);
    report("DTBSV", dx[0] != 1.0);

    zy[0] = 0; cblas_zhpmv(CblasRowMajor, CblasUpper, 2, &zalpha, zAp, zx, 1, &zbeta, zy, 1);
    report("ZHPMV", creal(zy[0]) != 0);

    dy[0] = 0; cblas_dspmv(CblasRowMajor, CblasUpper, 2, 1.0, dAp, dx, 1, 0.0, dy, 1);
    report("DSPMV", dy[0] != 0);

    dx[0] = 1.0; cblas_dtpmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 2, dAp, dx, 1);
    report("DTPMV", dx[0] != 1.0);

    dx[0] = 1.0; cblas_dtpsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 2, dAp, dx, 1);
    report("DTPSV", dx[0] != 1.0);

    dAp[0] = 10.0; cblas_dspr(CblasRowMajor, CblasUpper, 2, 1.0, dx, 1, dAp);
    report("DSPR", dAp[0] != 10.0);

    zAp[0] = 10.0; cblas_zhpr(CblasRowMajor, CblasUpper, 2, 1.0, zx, 1, zAp);
    report("ZHPR", creal(zAp[0]) != 10.0);

    dAp[0] = 10.0; cblas_dspr2(CblasRowMajor, CblasUpper, 2, 1.0, dx, 1, dy, 1, dAp);
    report("DSPR2", dAp[0] != 10.0);

    zAp[0] = 10.0; cblas_zhpr2(CblasRowMajor, CblasUpper, 2, &zalpha, zx, 1, zy, 1, zAp);
    report("ZHPR2", creal(zAp[0]) != 10.0);

    printf("=== ALL TESTS FINISHED ===\n");
    return 0;
}