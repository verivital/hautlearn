function [dx]=ex1_node_St2_FlowEq(x,u)

dx(1,1) = (0.5362024903297424*exp(0.604775071144104*x(1) + 0.5488911867141724*x(2) + 0.07835572957992554) - 0.5362024903297424)/(exp(0.604775071144104*x(1) + 0.5488911867141724*x(2) + 0.07835572957992554) + 1.0) - (0.3894966244697571*exp(0.1163388341665268*x(1) + 1.0107378959655762*x(2) + 0.05383792519569397) - 0.3894966244697571)/(exp(0.1163388341665268*x(1) + 1.0107378959655762*x(2) + 0.05383792519569397) + 1.0) - (0.4801105260848999*exp(0.6028870344161987*x(2) - 0.7738447189331055*x(1) + 0.09245716035366058) - 0.4801105260848999)/(exp(0.6028870344161987*x(2) - 0.7738447189331055*x(1) + 0.09245716035366058) + 1.0) - (0.3144373297691345*exp(0.6887566447257996*x(1) + 0.4987463057041168*x(2) - 0.10281724482774734) - 0.3144373297691345)/(exp(0.6887566447257996*x(1) + 0.4987463057041168*x(2) - 0.10281724482774734) + 1.0) - (0.42704156041145325*exp(0.6177901029586792*x(2) - 0.4676801562309265*x(1) + 0.01174979843199253) - 0.42704156041145325)/(exp(0.6177901029586792*x(2) - 0.4676801562309265*x(1) + 0.01174979843199253) + 1.0) - (0.22417937219142914*exp(0.3105676770210266*x(2) - 0.4884205162525177*x(1) + 0.09676644206047058) - 0.22417937219142914)/(exp(0.3105676770210266*x(2) - 0.4884205162525177*x(1) + 0.09676644206047058) + 1.0) - (0.3586192727088928*exp(0.23055383563041687*x(1) - 0.3186957836151123*x(2) + 0.09966936707496643) - 0.3586192727088928)/(exp(0.23055383563041687*x(1) - 0.3186957836151123*x(2) + 0.09966936707496643) + 1.0) + (0.35343942046165466*exp(0.7641435861587524*x(1) - 0.45938730239868164*x(2) + 0.014588812366127968) - 0.35343942046165466)/(exp(0.7641435861587524*x(1) - 0.45938730239868164*x(2) + 0.014588812366127968) + 1.0) - (0.5087916254997253*exp(0.6394046545028687*x(1) - 0.6333951354026794*x(2) + 0.07158142328262329) - 0.5087916254997253)/(exp(0.6394046545028687*x(1) - 0.6333951354026794*x(2) + 0.07158142328262329) + 1.0) + (0.1568225473165512*exp(0.17216528952121735*x(1) + 1.046384334564209*x(2) + 0.0010911826975643635) - 0.1568225473165512)/(exp(0.17216528952121735*x(1) + 1.046384334564209*x(2) + 0.0010911826975643635) + 1.0) - (0.2664828598499298*exp(0.8175243735313416*x(2) - 0.14570258557796478*x(1) + 0.0789196565747261) - 0.2664828598499298)/(exp(0.8175243735313416*x(2) - 0.14570258557796478*x(1) + 0.0789196565747261) + 1.0) - (0.5020380616188049*exp(0.615638792514801*x(1) - 0.7856979370117188*x(2) + 0.18128538131713867) - 0.5020380616188049)/(exp(0.615638792514801*x(1) - 0.7856979370117188*x(2) + 0.18128538131713867) + 1.0) + (0.4003770649433136*exp(0.5251650214195251*x(1) + 0.0374409444630146*x(2) + 0.17754621803760529) - 0.4003770649433136)/(exp(0.5251650214195251*x(1) + 0.0374409444630146*x(2) + 0.17754621803760529) + 1.0) + (0.1035316213965416*exp(0.19428350031375885*x(1) + 1.0496068000793457*x(2) + 0.03221691772341728) - 0.1035316213965416)/(exp(0.19428350031375885*x(1) + 1.0496068000793457*x(2) + 0.03221691772341728) + 1.0) - (0.12505723536014557*exp(0.8433523774147034*x(1) + 0.8931418657302856*x(2) - 0.06894798576831818) - 0.12505723536014557)/(exp(0.8433523774147034*x(1) + 0.8931418657302856*x(2) - 0.06894798576831818) + 1.0) - (0.31106022000312805*exp(0.08418424427509308*x(1) + 0.283954918384552*x(2) - 0.0308680459856987) - 0.31106022000312805)/(exp(0.08418424427509308*x(1) + 0.283954918384552*x(2) - 0.0308680459856987) + 1.0) - (0.3760240375995636*exp(0.5433180332183838*x(1) + 0.061846088618040085*x(2) + 0.07081878185272217) - 0.3760240375995636)/(exp(0.5433180332183838*x(1) + 0.061846088618040085*x(2) + 0.07081878185272217) + 1.0) + (0.16113443672657013*exp(0.23439587652683258*x(1) + 0.389376699924469*x(2) + 0.06722152233123779) - 0.16113443672657013)/(exp(0.23439587652683258*x(1) + 0.389376699924469*x(2) + 0.06722152233123779) + 1.0) + (0.031713396310806274*exp(0.8288009762763977*x(1) - 0.9553812742233276*x(2) + 0.03843358904123306) - 0.031713396310806274)/(exp(0.8288009762763977*x(1) - 0.9553812742233276*x(2) + 0.03843358904123306) + 1.0) + (0.11881831288337708*exp(0.7476024627685547*x(1) - 0.5308956503868103*x(2) + 0.04502331465482712) - 0.11881831288337708)/(exp(0.7476024627685547*x(1) - 0.5308956503868103*x(2) + 0.04502331465482712) + 1.0) + 0.01631726697087288;

dx(2,1) = (0.3387020528316498*exp(0.23055383563041687*x(1) - 0.3186957836151123*x(2) + 0.09966936707496643) - 0.3387020528316498)/(exp(0.23055383563041687*x(1) - 0.3186957836151123*x(2) + 0.09966936707496643) + 1.0) - (0.17632551491260529*exp(0.1163388341665268*x(1) + 1.0107378959655762*x(2) + 0.05383792519569397) - 0.17632551491260529)/(exp(0.1163388341665268*x(1) + 1.0107378959655762*x(2) + 0.05383792519569397) + 1.0) - (0.22115595638751984*exp(0.615638792514801*x(1) - 0.7856979370117188*x(2) + 0.18128538131713867) - 0.22115595638751984)/(exp(0.615638792514801*x(1) - 0.7856979370117188*x(2) + 0.18128538131713867) + 1.0) - (0.34705162048339844*exp(0.6177901029586792*x(2) - 0.4676801562309265*x(1) + 0.01174979843199253) - 0.34705162048339844)/(exp(0.6177901029586792*x(2) - 0.4676801562309265*x(1) + 0.01174979843199253) + 1.0) + (0.24699389934539795*exp(0.5433180332183838*x(1) + 0.061846088618040085*x(2) + 0.07081878185272217) - 0.24699389934539795)/(exp(0.5433180332183838*x(1) + 0.061846088618040085*x(2) + 0.07081878185272217) + 1.0) + (0.40590399503707886*exp(0.3105676770210266*x(2) - 0.4884205162525177*x(1) + 0.09676644206047058) - 0.40590399503707886)/(exp(0.3105676770210266*x(2) - 0.4884205162525177*x(1) + 0.09676644206047058) + 1.0) - (0.24228310585021973*exp(0.8433523774147034*x(1) + 0.8931418657302856*x(2) - 0.06894798576831818) - 0.24228310585021973)/(exp(0.8433523774147034*x(1) + 0.8931418657302856*x(2) - 0.06894798576831818) + 1.0) + (0.22574880719184875*exp(0.8288009762763977*x(1) - 0.9553812742233276*x(2) + 0.03843358904123306) - 0.22574880719184875)/(exp(0.8288009762763977*x(1) - 0.9553812742233276*x(2) + 0.03843358904123306) + 1.0) + (0.3543780744075775*exp(0.7641435861587524*x(1) - 0.45938730239868164*x(2) + 0.014588812366127968) - 0.3543780744075775)/(exp(0.7641435861587524*x(1) - 0.45938730239868164*x(2) + 0.014588812366127968) + 1.0) + (0.5423222184181213*exp(0.19428350031375885*x(1) + 1.0496068000793457*x(2) + 0.03221691772341728) - 0.5423222184181213)/(exp(0.19428350031375885*x(1) + 1.0496068000793457*x(2) + 0.03221691772341728) + 1.0) - (0.5155855417251587*exp(0.6394046545028687*x(1) - 0.6333951354026794*x(2) + 0.07158142328262329) - 0.5155855417251587)/(exp(0.6394046545028687*x(1) - 0.6333951354026794*x(2) + 0.07158142328262329) + 1.0) + (0.014472335577011108*exp(0.6887566447257996*x(1) + 0.4987463057041168*x(2) - 0.10281724482774734) - 0.014472335577011108)/(exp(0.6887566447257996*x(1) + 0.4987463057041168*x(2) - 0.10281724482774734) + 1.0) + (0.35056835412979126*exp(0.17216528952121735*x(1) + 1.046384334564209*x(2) + 0.0010911826975643635) - 0.35056835412979126)/(exp(0.17216528952121735*x(1) + 1.046384334564209*x(2) + 0.0010911826975643635) + 1.0) + (0.11538253724575043*exp(0.604775071144104*x(1) + 0.5488911867141724*x(2) + 0.07835572957992554) - 0.11538253724575043)/(exp(0.604775071144104*x(1) + 0.5488911867141724*x(2) + 0.07835572957992554) + 1.0) + (0.03549620136618614*exp(0.08418424427509308*x(1) + 0.283954918384552*x(2) - 0.0308680459856987) - 0.03549620136618614)/(exp(0.08418424427509308*x(1) + 0.283954918384552*x(2) - 0.0308680459856987) + 1.0) + (0.3996223211288452*exp(0.7476024627685547*x(1) - 0.5308956503868103*x(2) + 0.04502331465482712) - 0.3996223211288452)/(exp(0.7476024627685547*x(1) - 0.5308956503868103*x(2) + 0.04502331465482712) + 1.0) + (0.24572955071926117*exp(0.5251650214195251*x(1) + 0.0374409444630146*x(2) + 0.17754621803760529) - 0.24572955071926117)/(exp(0.5251650214195251*x(1) + 0.0374409444630146*x(2) + 0.17754621803760529) + 1.0) + (0.0992613136768341*exp(0.8175243735313416*x(2) - 0.14570258557796478*x(1) + 0.0789196565747261) - 0.0992613136768341)/(exp(0.8175243735313416*x(2) - 0.14570258557796478*x(1) + 0.0789196565747261) + 1.0) + (0.076938696205616*exp(0.23439587652683258*x(1) + 0.389376699924469*x(2) + 0.06722152233123779) - 0.076938696205616)/(exp(0.23439587652683258*x(1) + 0.389376699924469*x(2) + 0.06722152233123779) + 1.0) + (0.19099585711956024*exp(0.6028870344161987*x(2) - 0.7738447189331055*x(1) + 0.09245716035366058) - 0.19099585711956024)/(exp(0.6028870344161987*x(2) - 0.7738447189331055*x(1) + 0.09245716035366058) + 1.0) + 0.08348819613456726;