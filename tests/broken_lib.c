#include "cblas.h"

void cblas_dgemv(CBLAS_ORDER o, CBLAS_TRANSPOSE t, int M, int N, double a, const double *A, int lda, const double *X, int iX, double b, double *Y, int iY) {}
void cblas_zhemv(CBLAS_ORDER o, CBLAS_UPLO u, int N, const void *a, const void *A, int lda, const void *X, int iX, const void *b, void *Y, int iY) {}
void cblas_dsymv(CBLAS_ORDER o, CBLAS_UPLO u, int N, double a, const double *A, int lda, const double *X, int iX, double b, double *Y, int iY) {}
void cblas_dtrmv(CBLAS_ORDER o, CBLAS_UPLO u, CBLAS_TRANSPOSE t, CBLAS_DIAG d, int N, const double *A, int lda, double *X, int iX) {}
void cblas_dtrsv(CBLAS_ORDER o, CBLAS_UPLO u, CBLAS_TRANSPOSE t, CBLAS_DIAG d, int N, const double *A, int lda, double *X, int iX) {}
void cblas_dger(CBLAS_ORDER o, int M, int N, double a, const double *X, int iX, const double *Y, int iY, double *A, int lda) {}
void cblas_zgeru(CBLAS_ORDER o, int M, int N, const void *a, const void *X, int iX, const void *Y, int iY, void *A, int lda) {}
void cblas_zgerc(CBLAS_ORDER o, int M, int N, const void *a, const void *X, int iX, const void *Y, int iY, void *A, int lda) {}
void cblas_dsyr(CBLAS_ORDER o, CBLAS_UPLO u, int N, double a, const double *X, int iX, double *A, int lda) {}
void cblas_zher(CBLAS_ORDER o, CBLAS_UPLO u, int N, double a, const void *X, int iX, void *A, int lda) {}
void cblas_dsyr2(CBLAS_ORDER o, CBLAS_UPLO u, int N, double a, const double *X, int iX, const double *Y, int iY, double *A, int lda) {}
void cblas_zher2(CBLAS_ORDER o, CBLAS_UPLO u, int N, const void *a, const void *X, int iX, const void *Y, int iY, void *A, int lda) {}
void cblas_dgbmv(CBLAS_ORDER o, CBLAS_TRANSPOSE t, int M, int N, int KL, int KU, double a, const double *A, int lda, const double *X, int iX, double b, double *Y, int iY) {}
void cblas_zhbmv(CBLAS_ORDER o, CBLAS_UPLO u, int N, int K, const void *a, const void *A, int lda, const void *X, int iX, const void *b, void *Y, int iY) {}
void cblas_dsbmv(CBLAS_ORDER o, CBLAS_UPLO u, int N, int K, double a, const double *A, int lda, const double *X, int iX, double b, double *Y, int iY) {}
void cblas_dtbmv(CBLAS_ORDER o, CBLAS_UPLO u, CBLAS_TRANSPOSE t, CBLAS_DIAG d, int N, int K, const double *A, int lda, double *X, int iX) {}
void cblas_dtbsv(CBLAS_ORDER o, CBLAS_UPLO u, CBLAS_TRANSPOSE t, CBLAS_DIAG d, int N, int K, const double *A, int lda, double *X, int iX) {}
void cblas_zhpmv(CBLAS_ORDER o, CBLAS_UPLO u, int N, const void *a, const void *Ap, const void *X, int iX, const void *b, void *Y, int iY) {}
void cblas_dspmv(CBLAS_ORDER o, CBLAS_UPLO u, int N, double a, const double *Ap, const double *X, int iX, double b, double *Y, int iY) {}
void cblas_dtpmv(CBLAS_ORDER o, CBLAS_UPLO u, CBLAS_TRANSPOSE t, CBLAS_DIAG d, int N, const double *Ap, double *X, int iX) {}
void cblas_dtpsv(CBLAS_ORDER o, CBLAS_UPLO u, CBLAS_TRANSPOSE t, CBLAS_DIAG d, int N, const double *Ap, double *X, int iX) {}
void cblas_dspr(CBLAS_ORDER o, CBLAS_UPLO u, int N, double a, const double *X, int iX, double *Ap) {}
void cblas_zhpr(CBLAS_ORDER o, CBLAS_UPLO u, int N, double a, const void *X, int iX, void *Ap) {}
void cblas_dspr2(CBLAS_ORDER o, CBLAS_UPLO u, int N, double a, const double *X, int iX, const double *Y, int iY, double *Ap) {}
void cblas_zhpr2(CBLAS_ORDER o, CBLAS_UPLO u, int N, const void *a, const void *X, int iX, const void *Y, int iY, void *Ap) {}