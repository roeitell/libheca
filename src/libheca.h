/*
 * libheca.h -- interface of the 'libheca' library
 *
 * Steve Walsh <steve.walsh@sap.com>
 * Aidan Shribman <aidan.shribman@sap.com>
 */
 
#ifndef LIBHECA_H_
#define LIBHECA_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <netinet/in.h>
#include <linux/heca.h>

int heca_open(void);

void heca_close(int fd);

int heca_dsm_init(int fd, struct svm_data *local_svm);

int heca_svm_add(int fd, int local_svm_id, int svm_count, struct svm_data
        *svm_array);

int heca_mr_add(int fd, int mr_count, struct unmap_data *unmap_array);

int heca_mr_pushback(int fd, int mr_count, struct unmap_data *unmap_array);

/*
    heca_master_open: initializes the master node for a heca connection. The
    function requires a pre-initialized svm_arry and mr_array. The auto_unmap 
    flag tells libheca to automatically unmap the memory region when creating 
    it. There are some cases where the user may not way to automatically unmap 
    this memory region and do so at a later stage when more information is 
    known about the system.
 */
int heca_master_open(int svm_count, struct svm_data *svm_array, int mr_count,
        struct unmap_data *mr_array);

/* 
    heca_client_open: initializes the client node for a heca connection. 
 */
int heca_client_open(void *dsm_mem, unsigned long dsm_mem_sz, int local_svm_id,
        struct sockaddr_in *master_addr);

#ifdef __cplusplus
}
#endif

#endif /* LIBHECA_H_ */

