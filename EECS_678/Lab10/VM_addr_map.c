#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAXSTR 1000

int main(int argc, char *argv[])
{
  char line[MAXSTR];
  int *page_table, *mem_map, *frame_map; //1D arrays - mem_map table is frame table to keep backwards matching, page_table from table to frame - added frame_map to help with page fault
  unsigned int log_size, phy_size, page_size, d; //sizes of things, d is offset
  unsigned int num_pages, num_frames;
  unsigned int offset, logical_addr, physical_addr, page_num, frame_num;

  /* Get the memory characteristics from the input file */
  fgets(line, MAXSTR, stdin);
  if((sscanf(line, "Logical address space size: %d^%d", &d, &log_size)) != 2){
    fprintf(stderr, "Unexpected line 1. Abort.\n");
    exit(-1);
  }
  fgets(line, MAXSTR, stdin);
  if((sscanf(line, "Physical address space size: %d^%d", &d, &phy_size)) != 2){
    fprintf(stderr, "Unexpected line 2. Abort.\n");
    exit(-1);
  }
  fgets(line, MAXSTR, stdin);
  if((sscanf(line, "Page size: %d^%d", &d, &page_size)) != 2){
    fprintf(stderr, "Unexpected line 3. Abort.\n");
    exit(-1);
  }
  
  /* Allocate arrays to hold the page table and memory frames map */
  //Have as many pages as number of bits represented (2 bits = 4 pages)
  num_pages = pow(2, (phy_size - page_size));
  num_frames = pow(2, (phy_size - page_size));
  printf("Number of Pages: %d, ", num_pages);
  printf("Number of Frames: %d\n\n", num_frames);
  u_int32_t temp = ((u_int32_t)0xffffffff) >> (unsigned)log2(num_pages);
  frame_map = (int*)calloc(num_frames, sizeof(int));

  /* Initialize page table to indicate that no pages are currently mapped to
     physical memory */
  page_table = (int*)calloc(0, sizeof(int));

  /* Initialize memory map table to indicate no valid frames */
  mem_map = (int*)calloc(num_pages, sizeof(int));

  /* Read each accessed address from input file. Map the logical address to
     corresponding physical address */
  fgets(line, MAXSTR, stdin);
  while(!(feof(stdin))){
    sscanf(line, "0x%x", &logical_addr);
    fprintf(stdout, "Logical address: 0x%x\n", logical_addr);
    
	/* Calculate page number and offset from the logical address */
	page_num = logical_addr >> page_size;
	printf("Page Number: %x\n", page_num);
	offset = (logical_addr & temp);

    /* Form corresponding physical address */
    //Follow format from the lab write-up
    physical_addr = offset | (page_table[page_num] << (32 - (int)log2(num_frames)));
    
    if(mem_map[page_num] == 0)
    {
    	printf("Page Fault!\n");
    	frame_num = 0;
    	while(frame_map[frame_num] == 1)
    	{
    		frame_num++;
    	}
    	page_table[page_num] = frame_num;
    	physical_addr = offset | (page_table[page_num] << (32 - (unsigned)log2(num_frames)));
    	frame_map[frame_num] = 1;
    	mem_map[page_num] = 1;
    }
    
    printf("Frame number: %x\n", page_table[page_num]);
    printf("Physical address: 0x%x\n\n", physical_addr);

    /* Read next line */
    fgets(line, MAXSTR, stdin);    
  }
  free(page_table);
  free(mem_map);
  free(frame_map);
  return 0;
}
