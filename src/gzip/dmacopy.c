
#include <ultra64.h>

/*-----------------------------------------------------------------------------
  DMA�]��
	u32	  src_addr : �ǂݍ��݌��J�[�g���b�W�A�h���X
	void* dest_addr: �o�͐惁�C���������A�h���X
	u32	  size	   : �]���T�C�Y(�o�C�g��)
-----------------------------------------------------------------------------*/

#define DMAREADBLOCK 8192

OSPiHandle *osCartRomHandle() {
	static OSPiHandle *cartHandle = NULL;

	if(cartHandle == NULL) {
		cartHandle = osCartRomInit();
	}

	return cartHandle;
}

u32 auRomDataRead(u32 src_addr, void* dest_addr, u32 size)
{
	static OSMesgQueue RomMessageQ;
	static OSMesg      RomMessageBuf;
	static int         initialized = 0;

	OSIoMesg dmaIoMesgBuf;
	u32 romaddr, memaddr, sizectr, readlen;

	if(!initialized) {
		osCreateMesgQueue(&RomMessageQ, &RomMessageBuf, 1);
		initialized = 1;
	}

	// CPU�L���b�V���̖�����
	osInvalDCache((void*)dest_addr, (s32)size);

	sizectr = size;
	romaddr = src_addr;
	memaddr = (u32)dest_addr;

	while(sizectr) {
		readlen = MIN(sizectr, DMAREADBLOCK);

		dmaIoMesgBuf.hdr.pri      = OS_MESG_PRI_NORMAL;
		dmaIoMesgBuf.hdr.retQueue = &RomMessageQ;
		dmaIoMesgBuf.dramAddr     = (void *)memaddr;
		dmaIoMesgBuf.devAddr      = romaddr;
		dmaIoMesgBuf.size         = readlen;

		osEPiStartDma(osCartRomHandle(), &dmaIoMesgBuf, OS_READ);

		romaddr += readlen;
		memaddr += readlen;
		sizectr -= readlen;

		// DMA�]���I���܂ő҂�
		osRecvMesg(&RomMessageQ, NULL, OS_MESG_BLOCK);
	}

	return (u32)dest_addr + size;
}

