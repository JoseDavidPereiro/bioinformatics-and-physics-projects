%%%%% Part d of Problem1%%%%%%%%%%%%%%%%%%%
close all
clear all
clc
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
t_start = tic; %Start of runtime measuring
%Number of cells in the population and extent of the simulation
c = 1000; %no. of cell
dt = 1/1000; %Time step of the simulation (minute)
t_max = 1/3; %Number of iterations to be run for the simulation in minutes
%% Initializing the molecule matrices and time vector
t =0:dt:t_max; %Vector containing time of occurrence of events
n = length(t) - 1;
rna_pop = zeros(c, length(t));
pr_pop = zeros(c, length(t));

for j =1:c
	rna = zeros(length(t),1); %Vector containing RNA molecules at any given time
	pr = zeros(length(t),1); %Vector containing protein molecules at any given time
	kr = 1; %RNA generation rate (molecules/minute)
	gr = 1/5; %RNA destruction rate (molecules/minute)
	kp = 60; %Protein generation rate (molecules/minute)
	gp = 1/30; %Protein degradation rate (molecules/minute)
	kh = 120; %Affinity K parameter of the Hill Equation
	for i = 1:n
		rna_t = rna(i);
		pr_t = pr(i);
	
		k1 = kr/(1+(pr_t/kh)^2) * dt; %Assigning of the creation rate for the calculation of the time of RNA creation events
		k2 = gr * rna_t * dt; %Assigning of the degradation rate for the calculation of the time of RNA degradation events
		k3 = kp * rna_t * dt; %Assigning of the creation rate for the calculation of the time of protein creation events
		k4 = gp * pr_t * dt; %Assigning of the degradation rate for the calculation of the time of protein degradation events
		
		event = rand;
		if event <= k1
			rna(i+1) = rna_t + 1;
		else
			event2 = rand;
			if event2 <= k2
				rna(i+1) = rna_t - 1;
			else
				rna(i+1) = rna_t;
			end
		end

		event3 = rand;
		if event3 <= k3
			pr(i+1) = pr_t + 1;
		else
			event4 = rand;
			if event4 <= k4
				pr(i+1) = pr_t - 1;
			else
				pr(i+1) = pr_t;
			end
		end
	end
	%Time regularization and addition to regularized time matrix
	rna_pop(j,:) = rna;
	pr_pop(j,:) = pr;
end

%% End of runtime measuring
time.elasped=toc(t_start);

%% Finding average values and noise of the RNA and protein distributions through time in the simulations
avg_rna = mean(rna_pop);
sd_rna = std(rna_pop);
noise_rna = sd_rna/avg_rna;

avg_pr = mean(pr_pop);
sd_pr = std(pr_pop);
noise_pr = sd_pr/avg_pr;
% Distribution of the RNA and protein molecules at steady state
dist_rna = rna_pop(:,length(rna_pop(1,:)));
dist_pr = pr_pop(:,length(pr_pop(1,:)));

%% Plotting the results
figure
subplot(2,2,1)
plot(t, avg_rna) 
xlabel('Time (minutes)');
ylabel('Average RNA molecules');%RNA molecules against time

subplot(2,2,2)
histogram(dist_rna) 
xlabel('RNA molecules at steady state');
ylabel('Frequency');%RNA molecules against time
%title(strcat('Average',num2str(round(time.elasped,4)),' minutes'));
subplot(2,2,3)
plot(t, avg_pr) 
xlabel('Time (minutes)');
ylabel('Average Protein molecules');%Protein molecules against time
title(strcat('Total execution time:',num2str(round(time.elasped,4)),' minutes'));

subplot(2,2,4)
histogram(dist_pr) 
xlabel('Protein molecules at steady state');
ylabel('Frequency');%RNA molecules against time


