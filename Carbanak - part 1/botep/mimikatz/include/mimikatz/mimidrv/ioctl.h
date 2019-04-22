/*	Benjamin DELPY `gentilkiwi`
	http://blog.gentilkiwi.com
	benjamin@gentilkiwi.com
	Licence : http://creativecommons.org/licenses/by/3.0/fr/
*/
#define IOCTL_MIMIDRV_RAW					CTL_CODE(FILE_DEVICE_UNKNOWN, 0x000, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)
#define IOCTL_MIMIDRV_PING					CTL_CODE(FILE_DEVICE_UNKNOWN, 0x001, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)
#define IOCTL_MIMIDRV_BSOD					CTL_CODE(FILE_DEVICE_UNKNOWN, 0x002, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)

#define IOCTL_MIMIDRV_PROCESS_LIST			CTL_CODE(FILE_DEVICE_UNKNOWN, 0x010, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)
#define IOCTL_MIMIDRV_PROCESS_TOKEN			CTL_CODE(FILE_DEVICE_UNKNOWN, 0x011, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)
#define IOCTL_MIMIDRV_PROCESS_PROTECT		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x012, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)
#define IOCTL_MIMIDRV_PROCESS_FULLPRIV		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x013, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)

#define IOCTL_MIMIDRV_MODULE_LIST			CTL_CODE(FILE_DEVICE_UNKNOWN, 0x020, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)

#define IOCTL_MIMIDRV_SSDT_LIST				CTL_CODE(FILE_DEVICE_UNKNOWN, 0x030, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)

#define IOCTL_MIMIDRV_NOTIFY_PROCESS_LIST	CTL_CODE(FILE_DEVICE_UNKNOWN, 0x040, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)
#define IOCTL_MIMIDRV_NOTIFY_THREAD_LIST	CTL_CODE(FILE_DEVICE_UNKNOWN, 0x041, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)
#define IOCTL_MIMIDRV_NOTIFY_IMAGE_LIST		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x042, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)
#define IOCTL_MIMIDRV_NOTIFY_REG_LIST		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x043, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)
#define IOCTL_MIMIDRV_NOTIFY_OBJECT_LIST	CTL_CODE(FILE_DEVICE_UNKNOWN, 0x044, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)

#define IOCTL_MIMIDRV_FILTER_LIST			CTL_CODE(FILE_DEVICE_UNKNOWN, 0x050, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)
#define IOCTL_MIMIDRV_MINIFILTER_LIST		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x051, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)

typedef struct _PS_PROTECTION {
	UCHAR Type	: 3;
	UCHAR Audit	: 1;
	UCHAR Signer: 4;
} PS_PROTECTION, *PPS_PROTECTION;

typedef struct _KIWI_PROCESS_SIGNATURE_PROTECTION {
	UCHAR SignatureLevel;
	UCHAR SectionSignatureLevel;
	PS_PROTECTION Protection;
} KIWI_PROCESS_SIGNATURE_PROTECTION, *PKIWI_PROCESS_SIGNATURE_PROTECTION;

typedef struct _MIMIDRV_PROCESS_PROTECT_INFORMATION {
	ULONG processId;
	KIWI_PROCESS_SIGNATURE_PROTECTION SignatureProtection;
} MIMIDRV_PROCESS_PROTECT_INFORMATION, *PMIMIDRV_PROCESS_PROTECT_INFORMATION;

typedef struct _MIMIDRV_PROCESS_TOKEN_FROM_TO {
	ULONG fromProcessId;
	ULONG toProcessId;
} MIMIDRV_PROCESS_TOKEN_FROM_TO, *PMIMIDRV_PROCESS_TOKEN_FROM_TO;