// WebRtcAudioTest.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "echo_control_mobile.h"

int WebRtcAecTest()
{
#define NN 160
	short far_frame[NN];
	short near_frame[NN];
	short out_frame[NN];

	void *aecmInst = NULL;
	FILE *fp_far = fopen("speaker.pcm", "rb");
	FILE *fp_near = fopen("micin.pcm", "rb");
	FILE *fp_out = fopen("out.pcm", "wb");

	do
	{
		if (!fp_far || !fp_near || !fp_out)
		{
			printf("WebRtcAecTest open file err \n");
			break;
		}

		WebRtcAecm_Create(&aecmInst);
		WebRtcAecm_Init(aecmInst, 8000);
		AecmConfig config;
		config.cngMode = 1;
		config.echoMode = 1;
		WebRtcAecm_set_config(aecmInst, config);

		while (1)
		{
			if (NN == fread(far_frame, sizeof(short), NN, fp_far))
			{
				fread(near_frame, sizeof(short), NN, fp_near);
				WebRtcAecm_BufferFarend(aecmInst, far_frame, NN);

				WebRtcAecm_Process(aecmInst, near_frame, NULL, out_frame, NN, 100);
				fwrite(out_frame, sizeof(short), NN, fp_out);
			}
			else
			{
				break;
			}
		}
	} while (0);

	fclose(fp_far);
	fclose(fp_near);
	fclose(fp_out);
	WebRtcAecm_Free(aecmInst);
	return 0;
}

int main(int argc, char *argv[])
{
	WebRtcAecTest();

	printf("Test is OK\n");

	return 0;
}
