#MIPS����  ���ۼӺ�                   sum_mips.asm                   	
#���ۼӺͣ�1+2+����+n��n��ֵΪ10�����Ըı䣩���ۼӺ͵Ľ����ŵ���ַΪ0�����ݴ洢����

main:	
	addi $s0,$zero,100                    # n=10 -> s0                              
	addi $s1,$zero,1               	#        1 -> s1              
	addi $s2,$zero,1               	#        1 -> s2
	addi $s3,$zero,0              	#        0 -> s3           
loop:
	add $s3,$s3,$s1                 	# s3+s1 -> s3                       
	beq $s1,$s0,finish              	# ���s1=s0����תfinish       
	add $s1,$s1,$s2                  	# s1+s2 -> s1     
	j loop
finish:
	sw $s3,0($zero)                	# s3 �浽��ַΪ0�Ĵ洢��Ԫ��

	addi   $v0,$zero,10         	# 10��ϵͳ����
	syscall                  		# �����˳�

