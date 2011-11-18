#ifndef LINUX_3_1_COMPAT_H
#define LINUX_3_1_COMPAT_H

#include <linux/version.h>

#if (LINUX_VERSION_CODE < KERNEL_VERSION(3,1,0))

#define genl_dump_check_consistent(cb, user_hdr, family)

#define IFF_TX_SKB_SHARING	0x10000	/* The interface supports sharing
					 * skbs on transmit */

#define PCMCIA_DEVICE_MANF_CARD_PROD_ID3(manf, card, v3, vh3) { \
	.match_flags = PCMCIA_DEV_ID_MATCH_MANF_ID| \
			PCMCIA_DEV_ID_MATCH_CARD_ID| \
			PCMCIA_DEV_ID_MATCH_PROD_ID3, \
	.manf_id = (manf), \
	.card_id = (card), \
	.prod_id = { NULL, NULL, (v3), NULL }, \
	.prod_id_hash = { 0, 0, (vh3), 0 }, }

/*
 * This has been defined in include/linux/security.h for some time, but was
 * only given an EXPORT_SYMBOL for 3.1.  Add a compat_* definition to avoid
 * breaking the compile.
 */
#define security_sk_clone(a, b) compat_security_sk_clone(a, b)

static inline void security_sk_clone(const struct sock *sk, struct sock *newsk)
{
}

#endif /* (LINUX_VERSION_CODE < KERNEL_VERSION(3,1,0)) */

#endif /* LINUX_3_1_COMPAT_H */
