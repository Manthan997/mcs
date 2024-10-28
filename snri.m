## Experiment 8 MCS

snrdB = [0,5,10,15,20];
numSamples = 100;
numClusters = 7;

clusterSizes = zeros(length(snrdB), numClusters);
voiceQualtiyScores = zeros(length(snrdB),1);

function quality = simulateVoiceQualtiy(snr)
  quality = max(0,min(100,10*snr));
end

for i = 1:length(snrdB)
  for j = 1:numClusters
    noise = randn(numSamples,1) * (10 / snrdB(i));
    clusterData = randn(numSamples,1) + noise;
    clusterSizes(i,j) = length(clusterData);
  endfor0

  voiceQualtiyScores(i) = simulateVoiceQualtiy(snrdB(i));
endfor

disp('Cluster sizes for Diff SNR lvls: ');
disp(clusterSizes);
disp('Voice Qualiy Scores for Diff SNR lvls: ');
disp(voiceQualtiyScores);

figure;
subplot(2,1,1);
bar(clusterSizes);
xlabel('SNR(dB)');
ylabel('Cluster Size: ');
title('Cluster sizes via SNR');
legend(arrayfun(@(x) sprintf('Cluster %d', x), 1:numClusters, 'UniformOutput', false));

subplot(2,1,2);
plot(snrdB,voiceQualtiyScores,'-o');
xlabel('SNR(dB)');
ylabel('voiceQualtiyScores');
title('Voice Quality vs SNR');
grid on;