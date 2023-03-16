#Harsh-Pathak
#15th june 17
#Steganograpy to add numbers
#Network/Cloud programming needed but lets simulate it anyway

# for addtion we will be sending this stream of data into a 3rd party cloud for addtion 
from operator import add
import math

# Sender Side Addition

s1 = '0'*10 + '1'*10 + '2'*10 + '3'*10 +'4'*10 +'5'*10 +'6'*10 +'7'*10 +'8'*10 +'9'*10
s2 = '0123456789'*10

# [+]Cloud Side addition
#    number 1 and number2 are used to perform partial addition
number1 = s1
number1 = list(str(number1))
number1 =  list(map(int,number1))

Number2 = s2
Number2 = list(str(Number2))
Number2 =  list(map(int,Number2))

result = list(map(add,number1,Number2))


encryptedResultbyServer=''
for i in result:
    encryptedResultbyServer+= str(i%10)

u = int(encryptedResultbyServer[30])
u = u%10

# Decryption on the Client Side
# lets suppose we want to add 53+37 then we will used something called a partial Bit

Num = '0123456789'
carrybit = 0

# Step 1 is to retrive the numbers that we are adding here it is
# 5 3
# 3 7
#______________
# just forget the carry for a moment ..We are additing MSB(5,3) and LSB(3,7)

####################################################################################
## ANSHUL 
#Just work from here....you only have to make n1 and n2 (shown below) as string values so that we can handle big integer values
#for addition of big nos 

####################################################################################

n1 = '531222222222222222232124143242453122222222222222223212414324245312222222222222222321241432424531222222222222222232124143242453122222222222222223212414324245312222222222222222321241432424531222222222222222232124143222222222222232124143222222222222232124143222222222222232124143222222222222232124143222222222222232124143222222222222232124143222222222222232124143' #Ans: Change to string
n2 = '379999999999999999999342656547423435379999999999999999999342656547423435379999999999999999999342656547423435379999999999999999999342656547423435379999999999999999999342656547423435379999999999999999999342656547423435379999999999999999999342656547423435379999999999999999999342656547423435' #Ans: Change to string


n1 = list(str(n1))
n1 =  list(map(int,n1))   #Ans: Convert string into list
print (' n1 done')

n2 = list(str(n2))
n2 =  list(map(int,n2))   #Ans: Convert string into list

print(n1)
print(n2)


#Temp variables to store n1 and n2 for further use if needed
N1=n1
N2=n2

ans = ''
temp = ''
i = 0
j = 0

# main decryption module

#while k < ( int(len(str(n1))):
i = int(len(n1)) #Ans: No need to convert into string
j = int(len(n2))  #Ans: No need to convert into string


print('Length of nos = '+ str(i))
print('Length of nos = '+ str(j))


# print('***Modifying the list to make their size same***')
#Ans: Appending the 0 to the starting of smallest list so as to make their size equal
if i > j :
  k = i-j
  while k>0:
    n2.insert(0,0)
    k = k-1
else :
  k = j-i
  while k>0:
    n1.insert(0,0)
    k = k-1
    
# print(n1)
# print(n2)
i = int(len(n1)) #Ans: No need to convert into string
# print('Length of nos = '+ str(i))
# print('Length of nos = '+ str(j))

    
while i>0:
    # bit_1 and bit_2 are the bits on which we are working say we are adding (23 + 45) then (bit1 and bit2 intilly will be (3,5))
  
  #Ans: Taking the last bit of the list.
    bit_1 = n1[i-1]
    bit_2 = n2[i-1]
   # print( ' Doing operation on bit no '+str(i) + ' i.e. '+ str(bit_1) + ' and ' + str(bit_2))
    
    
    temp = str(bit_1) + str(bit_2)
    #print(temp)
    x =  int (encryptedResultbyServer[int(temp)])
    #temp = 0
    K = x
    if carrybit == 0 :
        ans = str(K) + ans

    if carrybit == 1:
        K = (K+1)%10
        ans =  str(K) + ans
        
   # print(str(K)  + ' ' + str(bit_1))
    if int(K) <= bit_1 and int(K)<= bit_2 :#this means carry was generated
        carrybit = 1

    else:
        carrybit = 0


    i-=1

if carrybit == 1 :
    ans = '1' + ans

print('\nAnswer:  ')
print(ans)
print('\nLength of answer = '+ str(len(ans)))

    
