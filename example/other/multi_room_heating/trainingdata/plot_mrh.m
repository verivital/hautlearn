function plot_mrh(data_path,i)
    data = data_path + string(i) + ".mat";
    data = load(data);
    xout = data.xout;
    f = figure;
    hold on;
    plot(xout(:,1),'DisplayName','x_1');
    plot(xout(:,2),'DisplayName','x_2');
    plot(xout(:,3),'DisplayName','x_3');
    plot(xout(:,4),'DisplayName','x_4');
    xlabel('Time (s)')
    legend;
    figname = "Multi_Room_Heating_"+string(i)+".png";
    saveas(f,figname);
end

