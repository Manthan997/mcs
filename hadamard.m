N = 4;   ## assignment 2 HADAMARD&WALSH wala
hadamardMatrix = hadamard(N);
HadIdx = 0 : N-1;
M = log2(N) + 1;

disp('Hadamard Matrix');
disp(hadamardMatrix);

binHadIdx = fliplr(dec2bin(HadIdx,M)) - '0';
binSeqIdx =  zeros (N, M-1);

for k = M:-1:2
    binSeqIdx(:,k) = xor (binHadIdx(:,k), binHadIdx(:,k-1));
endfor

seqIdx = binSeqIdx*pow2((M-1:-1:0)');
walshMatrix = hadamardMatrix(seqIdx+1,:)
