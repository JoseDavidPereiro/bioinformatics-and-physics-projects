%%%%% Part a of Problem1%%%%%%%%%%%%%%%%%%%
close all
clear all
clc
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
t_start = tic; %Start of runtime measuring

%%Time modelling of creation and destruction events for RNA and Proteins in a single gene case with constant expression and degradation rates.

%Constants
kr = 1 ;%RNA generation rate (molecules/minute)
gr = 1/5; %RNA destruction rate (molecules/minute)
kp = 60; %Protein generation rate (molecules/minute)
gp = 1/30; %Protein degradation rate (molecules/minute)
dt = 1/1000; %Time step of the simulation (minute)
t_max = 10 ;%Simulation time in minutes

%Creation of the vectors that will store the values of the simulation with initial conditions
t =0:dt:t_max; %Vector containing time of occurrence of events
rna = zeros(length(t),1); %Vector containing RNA molecules at any given time
pr = zeros(length(t),1); %Vector containing protein molecules at any given time
n = length(t) - 1; %Maximum number of iterations 

for i = 1:n
	rna_t = rna(i);
	pr_t = pr(i);

	k1 = kr * dt; %Assigning of the creation rate for the calculation of the time of RNA creation events
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

%% End of runtime measuring
time.elasped=toc(t_start);

%% Plotting the results
figure
subplot(2,1,1)
plot(t, rna) 
xlabel('Time (minutes)');
ylabel('RNA molecules');%RNA molecules against time
subplot(2,1,2)
plot(t, pr) 
xlabel('Time (minutes)');
ylabel('Protein molecules');%Protein molecules against time
title(strcat('Total execution time:',num2str(round(time.elasped,4)),' minutes'));


