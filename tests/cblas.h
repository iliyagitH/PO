#ifndef CBLAS_H
#define CBLAS_H

#include <complex.h>

typedef enum {CblasRowMajor=101, CblasColMajor=102} CBLAS_ORDER;
typedef enum {CblasNoTrans=111, CblasTrans=112, CblasConjTrans=113} CBLAS_TRANSPOSE;
typedef enum {CblasUpper=121, CblasLower=122} CBLAS_UPLO;
typedef enum {CblasNonUnit=131, CblasUnit=132} CBLAS_DIAG;

void cblas_dgemv(const CBLAS_ORDER order, const CBLAS_TRANSPOSE TransA, const int M, const int N, const double alpha, const double *A, const int lda, const double *X, const int incX, const double beta, double *Y, const int incY);
void cblas_zhemv(const CBLAS_ORDER order, const CBLAS_UPLO Uplo, const int N, const void *alpha, const void *A, const int lda, const void *X, const int incX, const void *beta, void *Y, const int incY);
void cblas_dsymv(const CBLAS_ORDER order, const CBLAS_UPLO Uplo, const int N, const double alpha, const double *A, const int lda, const double *X, const int incX, const double beta, double *Y, const int incY);
void cblas_dtrmv(const CBLAS_ORDER order, const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag, const int N, const double *A, const int lda, double *X, const int incX);
void cblas_dtrsv(const CBLAS_ORDER order, const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag, const int N, const double *A, const int lda, double *X, const int incX);

void cblas_dger(const CBLAS_ORDER order, const int M, const int N, const double alpha, const double *X, const int incX, const double *Y, const int incY, double *A, const int lda);
void cblas_zgeru(const CBLAS_ORDER order, const int M, const int N, const void *alpha, const void *X, const int incX, const void *Y, const int incY, void *A, const int lda);
void cblas_zgerc(const CBLAS_ORDER order, const int M, const int N, const void *alpha, const void *X, const int incX, const void *Y, const int incY, void *A, const int lda);
void cblas_dsyr(const CBLAS_ORDER order, const CBLAS_UPLO Uplo, const int N, const double alpha, const double *X, const int incX, double *A, const int lda);
void cblas_zher(const CBLAS_ORDER order, const CBLAS_UPLO Uplo, const int N, const double alpha, const void *X, const int incX, void *A, const int lda);
void cblas_dsyr2(const CBLAS_ORDER order, const CBLAS_UPLO Uplo, const int N, const double alpha, const double *X, const int incX, const double *Y, const int incY, double *A, const int lda);
void cblas_zher2(const CBLAS_ORDER order, const CBLAS_UPLO Uplo, const int N, const void *alpha, const void *X, const int incX, const void *Y, const int incY, void *A, const int lda);

void cblas_dgbmv(const CBLAS_ORDER order, const CBLAS_TRANSPOSE TransA, const int M, const int N, const int KL, const int KU, const double alpha, const double *A, const int lda, const double *X, const int incX, const double beta, double *Y, const int incY);
void cblas_zhbmv(const CBLAS_ORDER order, const CBLAS_UPLO Uplo, const int N, const int K, const void *alpha, const void *A, const int lda, const void *X, const int incX, const void *beta, void *Y, const int incY);
void cblas_dsbmv(const CBLAS_ORDER order, const CBLAS_UPLO Uplo, const int N, const int K, const double alpha, const double *A, const int lda, const double *X, const int incX, const double beta, double *Y, const int incY);
void cblas_dtbmv(const CBLAS_ORDER order, const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag, const int N, const int K, const double *A, const int lda, double *X, const int incX);
void cblas_dtbsv(const CBLAS_ORDER order, const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag, const int N, const int K, const double *A, const int lda, double *X, const int incX);
void cblas_zhpmv(const CBLAS_ORDER order, const CBLAS_UPLO Uplo, const int N, const void *alpha, const void *Ap, const void *X, const int incX, const void *beta, void *Y, const int incY);
void cblas_dspmv(const CBLAS_ORDER order, const CBLAS_UPLO Uplo, const int N, const double alpha, const double *Ap, const double *X, const int incX, const double beta, double *Y, const int incY);
void cblas_dtpmv(const CBLAS_ORDER order, const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag, const int N, const double *Ap, double *X, const int incX);
void cblas_dtpsv(const CBLAS_ORDER order, const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag, const int N, const double *Ap, double *X, const int incX);
void cblas_dspr(const CBLAS_ORDER order, const CBLAS_UPLO Uplo, const int N, const double alpha, const double *X, const int incX, double *Ap);
void cblas_zhpr(const CBLAS_ORDER order, const CBLAS_UPLO Uplo, const int N, const double alpha, const void *X, const int incX, void *Ap);
void cblas_dspr2(const CBLAS_ORDER order, const CBLAS_UPLO Uplo, const int N, const double alpha, const double *X, const int incX, const double *Y, const int incY, double *Ap);
void cblas_zhpr2(const CBLAS_ORDER order, const CBLAS_UPLO Uplo, const int N, const void *alpha, const void *X, const int incX, const void *Y, const int incY, void *Ap);

#endif  