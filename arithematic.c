;***********************************************************************
;*   add.a	 DO NOT INCLUDE STARTUP.S IN YOUR PROJECT							  
;************************************************************************/
        AREA     ARMex, CODE, READONLY
                                ; Name this block of code ARMex
        ENTRY                   ; Mark first instruction to execute
main

    LDR R1, =0x00001133
    LDR R2, =0x00001111
	ADD R3, R1,R2
	
	;MOV R1, #0x33  ;R1 = 33   
	;MOV R2, #0x11  ;R2 = 11   
	;ADD R3, R1, R2  ;/* R3 = R1 + R2 */
HERE
	B HERE 	;/* End loop */

    END ;/* End of file */



;/***********************************************************************
;*   sub.a  DO NOT INCLUDE STARTUP.S IN UR PROJECT								  
;************************************************************************/
        AREA     ARMex, CODE, READONLY
                                ; Name this block of code ARMex
        ENTRY                   ; Mark first instruction to execute

main
;/* Write your assembly language code starting after this line. */
	MOV R1, #0x44     
	MOV R2, #0x11     
	SUB R3, R1, R2  ;/* R2 = R1 - R2 */
;/* Finish your assembly language code before this line. */
HERE
	B HERE 	;/* End loop */
	
	END ;/* End of file */
	

;/***********************************************************************
;*   mul_start.s	DO NOT INCLUDE STARTUP.S IN YOUR PROJECT							  
;************************************************************************/
        AREA     ARMex, CODE, READONLY
                                ; Name this block of code ARMex
        ENTRY                   ; Mark first instruction to execute

main
;/* Write your assembly language code starting after this line. */
	MOV R1, #0x5     
	MOV R2, #0x2     
	MUL R3, R1, R2  ;/* R2 = R1 x R2 */
;/* Finish your assembly language code before this line. */
HERE
	B HERE 	;/* End loop */
	END ;/* End of file */

	

;/***********************************************************************
;*   divide Program in Assembly
;  DO NOT INCLUDE STARTUP.S IN YOUR PROJECT							  
;************************************************************************/
        AREA     ARMex, CODE, READONLY
                                ; Name this block of code ARMex
        ENTRY                   ; Mark first instruction to execute
main
;/* Write your assembly language code starting after this line. */
	MOV R0, #100  ;/* Dividend */
	MOV R1, #10   ;/* Divider  */

	MOV R3, #0    ;/* Quotient in R3 */
LOOP 
      CMP R0, R1
      BLT DONE
      ADD R3, R3, #1  ;/* R3 = R3 + 1 */
      SUB R0, R0, R1  ;/* R0 = R0 - R1 */
      B   LOOP        ;/* Jump to LOOP */

;/* Quotient in R3 & Reminder in R0 */
DONE
;/* Finish your assembly language code before this line. */
HERE
	B HERE 	;/* End loop */
	END ;/* End of file */

