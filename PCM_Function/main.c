//
//  main.c
//  PCM_Function
//
//  Created by zhangyun on 16/4/21.
//  Copyright © 2016年 USC. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    
    // left channel volume half
    simplest_pcm16le_halfvolumeleft("/Users/zhangyun/iOSWorkSpace/PCM_Function/PCM_Function/44.1_liti.pcm");
    
    return 0;
}

/**
 * Halve volume of Left channel of 16LE PCM file
 * @param url  Location of PCM file.
 */
int simplest_pcm16le_halfvolumeleft(char *url){
    FILE *fp=fopen(url,"rb+");
    FILE *fp1=fopen("/Users/zhangyun/iOSWorkSpace/PCM_Function/PCM_Function/output_halfleft.pcm","wb+");
    
    int cnt=0;
    
    unsigned char *sample=(unsigned char *)malloc(4);
    
    while(!feof(fp)){
        short *samplenum=NULL;
        fread(sample,1,4,fp);
        
        samplenum=(short *)sample;
        *samplenum=*samplenum/2;
        //L
        fwrite(sample,1,2,fp1);
        //R
        fwrite(sample+2,1,2,fp1);
        
        cnt++;
    }
    printf("Sample Cnt:%d\n",cnt);
    
    free(sample);
    fclose(fp);
    fclose(fp1);
    return 0;
}

