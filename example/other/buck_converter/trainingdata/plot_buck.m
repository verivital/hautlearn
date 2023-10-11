function plot_buck(data_path,i)
    data = data_path + string(i) + ".mat";
    data = load(data);
    xout = data.xout;
    f = figure;
    hold on;
    plot(xout(:,3),xout(:,1),'DisplayName','x_1');
    plot(xout(:,3),xout(:,2),'DisplayName','x_2');
    plot(xout(:,3),xout(:,4),'DisplayName','loc');
    xlabel('Time (s)');
    legend;
    figname = "Buck_data_"+string(i)+".png";
    saveas(f,figname);
end

