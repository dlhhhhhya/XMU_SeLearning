# RISCV���� ð������ (��С����) (10������������磺8��1��5��2��7��9��6��4��3��10) 
# @Author : 22920212204392 ����

main:
        # step 1 ����
        ori s0,zero,10                             # n = 10
        sw s0,0(zero)         	                   # n �浽��ַΪ0�Ĵ洢��Ԫ��
        add t0,s0,zero                             # t0 ����ѭ������,�˴�Ӧ���� n-1
        ori s0,zero,-1
        add t0,t0,s0                               # ʵ�� t0=n-1

        ori s0,zero,8                              # 8 -> s0 
        sw s0,4(zero)                	# 8 �浽��ַΪ4�Ĵ洢��Ԫ��
        ori s0,zero,1                              # 1 -> s0 
        sw s0,8(zero)                	# 1 �浽��ַΪ8�Ĵ洢��Ԫ��
        ori s0,zero,5                              # 5 -> s0 
        sw s0,12(zero)                  # 5 �浽��ַΪ12�Ĵ洢��Ԫ��
        ori s0,zero,2                              # 2 -> s0 
        sw s0,16(zero)                	# 2 �浽��ַΪ16�Ĵ洢��Ԫ��
        ori s0,zero,7                              # 7 -> s0 
        sw s0,20(zero)                	# 7 �浽��ַΪ20�Ĵ洢��Ԫ��
        ori s0,zero,9                              # 9 -> s0 
        sw s0,24(zero)                	# 9 �浽��ַΪ24�Ĵ洢��Ԫ��
        ori s0,zero,6                              # 6 -> s0 
        sw s0,28(zero)                	# 6 �浽��ַΪ28�Ĵ洢��Ԫ��
        ori s0,zero,4                              # 4 -> s0 
        sw s0,32(zero)                	# 4 �浽��ַΪ32�Ĵ洢��Ԫ��
        ori s0,zero,3                              # 3 -> s0 
        sw s0,36(zero)                	# 3 �浽��ַΪ36�Ĵ洢��Ԫ��
        ori s0,zero,10                             # 10 -> s0 
        sw s0,40(zero)                	# 10 �浽��ַΪ40�Ĵ洢��Ԫ��

        # step 2 �Ƚ�
        ori s1,zero,0                          #s1��loop1��ѭ������
        ori s2,zero,0                          #s2��loop2��ѭ������
       
        ori s9,zero,1                          #���ں����ѭ����������1
        ori s10,zero,4                         #���ں���ĵ�ַs8��4
loop1:
        ori s8,zero,4                          #s8ָ��洢��Ԫ��ַ,ÿ�δӵ�һ�����ĵ�ַ4��ʼ
        ori s2,zero,0                          #ÿ��ִ�����ѭ��(loop1)�����ڲ�ѭ��(loop2)��ѭ��������Ϊ0
loop2:
        add s5,s8,zero                         #��ȡ��s8/4�����ĵ�ַ,����s5
        lw s3,0(s5)                            #��ȡ��s8/4����,����s3

        add s8,s8,s10                          #��ȡ��һ����ַ(s8ÿ��+4)

        add s6,s8,zero                         #��ȡ��s8/4+1�����ĵ�ַ,����s6
        lw s4,0(s6)                            #��ȡ��s8/4+1����,����s4
        
        slt s7,s4,s3                                                       
        beq s7,zero, skip                      # s3>s4,����,����skip
        sw s4,0(s5)
        sw s3,0(s6)
skip:
        add s2,s2,s9                           # �ڲ�ѭ���������������ж��Ƿ�����ѭ������
        add  s0,s1,s2                          # s0=s1+s2
        slt s7,t0,s0                           # t0>=s0,s7=0,����s7=1
        beq s7,zero,loop2                      # ������ѭ��
                    
        add s1,s1,s9                           # ���ѭ���������������ж��Ƿ�����ѭ������
        slt s7,t0,s1                           # t0>=s1,s7=0,����s7=1
        beq s7,zero,loop1                      # ������ѭ��

end:
        jal zero, end		# ��������ת��endִ��
