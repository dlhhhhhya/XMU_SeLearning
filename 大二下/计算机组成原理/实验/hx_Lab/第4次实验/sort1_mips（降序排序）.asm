# MIPS���ʵ��1 ð������ (�Ӵ�С) (10������������磺8��1��5��2��7��9��6��4��3��10) 
# @Author : 22920212204392 ����

main:
        # step 1 ����
        addi $s0,$zero,8                              # 8 -> s0 
        sw $s0,0($zero)                	        # 8 �浽��ַΪ0�Ĵ洢��Ԫ��
        addi $s0,$zero,1                              # 1 -> s0 
        sw $s0,4($zero)                	        # 1 �浽��ַΪ4�Ĵ洢��Ԫ��
        addi $s0,$zero,5                              # 5 -> s0 
        sw $s0,8($zero)                         # 5 �浽��ַΪ8�Ĵ洢��Ԫ��
        addi $s0,$zero,2                              # 2 -> s0 
        sw $s0,12($zero)                	# 2 �浽��ַΪ12�Ĵ洢��Ԫ��
        addi $s0,$zero,7                              # 7 -> s0 
        sw $s0,16($zero)                	# 7 �浽��ַΪ16�Ĵ洢��Ԫ��
        addi $s0,$zero,9                              # 9-> s0 
        sw $s0,20($zero)                	# 9 �浽��ַΪ20�Ĵ洢��Ԫ��
        addi $s0,$zero,6                              # 6 -> s0 
        sw $s0,24($zero)                	# 6 �浽��ַΪ24�Ĵ洢��Ԫ��
        addi $s0,$zero,4                              # 4 -> s0 
        sw $s0,28($zero)                	# 4 �浽��ַΪ28�Ĵ洢��Ԫ��
        addi $s0,$zero,3                              # 3 -> s0 
        sw $s0,32($zero)                	# 3 �浽��ַΪ32�Ĵ洢��Ԫ��
        addi $s0,$zero,10                             # 10 -> s0 
        sw $s0,36($zero)                	# 10 �浽��ַΪ36�Ĵ洢��Ԫ��

        # step 2 �Ƚ�
        addi $s1,$zero,0                        #s1��loop1��ѭ������
        addi $s2,$zero,0                        #s2��loop2��ѭ������
        addi $t0,$zero,9                        #t0����ѭ������
loop1:
        addi $s2,$zero,0                        # ÿ��ִ�����ѭ��(loop1)�����ڲ�ѭ��(loop2)��ѭ��������Ϊ0
loop2:
        addi $s0,$s2,0                                #��ȡ��$s2����(�ӵ�0������ʼ)
        sll $s5,$s0,2                                   #������λ,�൱�ڳ�4
        lw $s3,0($s5)
         
        addi $s0,$s2,1                               #��ȡ��$s2+1����
        sll $s6,$s0,2                                   #������λ,�൱�ڳ�4
        lw $s4,0($s6) 
        
        slt $s7,$s3,$s4                                 # $s3>s4, 1->s7,����0->s7
        beq $s7,$zero, skip                         # s3>s4,������,����skip
        sw $s4,0($s5)
        sw $s3,0($s6)
skip:
        addi $s2,$s2,1                                 # �ڲ�ѭ���������������ж��Ƿ�����ѭ������
        sub $s0,$t0,$s1
        bne $s2,$s0,loop2                          #������ѭ��
        addi $s1,$s1,1                                 #���ѭ���������������ж��Ƿ�����ѭ������
        sub $s0,$t0,$s1
        bne $s0,$zero,loop1

finish:
       	addi   $v0,$zero,10         	# 10��ϵͳ����
	syscall                  		# �����˳�
