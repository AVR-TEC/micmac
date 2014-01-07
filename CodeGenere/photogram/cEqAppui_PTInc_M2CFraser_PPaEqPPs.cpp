// File Automatically generated by eLiSe
#include "general/all.h"
#include "private/all.h"
#include "cEqAppui_PTInc_M2CFraser_PPaEqPPs.h"


cEqAppui_PTInc_M2CFraser_PPaEqPPs::cEqAppui_PTInc_M2CFraser_PPaEqPPs():
    cElCompiledFonc(2)
{
   AddIntRef (cIncIntervale("Intr",0,12));
   AddIntRef (cIncIntervale("Orient",12,18));
   AddIntRef (cIncIntervale("Tmp_PTer",18,21));
   Close(false);
}



void cEqAppui_PTInc_M2CFraser_PPaEqPPs::ComputeVal()
{
   double tmp0_ = mCompCoord[12];
   double tmp1_ = mCompCoord[13];
   double tmp2_ = cos(tmp1_);
   double tmp3_ = sin(tmp0_);
   double tmp4_ = cos(tmp0_);
   double tmp5_ = sin(tmp1_);
   double tmp6_ = mCompCoord[14];
   double tmp7_ = mCompCoord[18];
   double tmp8_ = mCompCoord[15];
   double tmp9_ = tmp7_-tmp8_;
   double tmp10_ = sin(tmp6_);
   double tmp11_ = -(tmp10_);
   double tmp12_ = -(tmp5_);
   double tmp13_ = cos(tmp6_);
   double tmp14_ = mCompCoord[19];
   double tmp15_ = mCompCoord[16];
   double tmp16_ = tmp14_-tmp15_;
   double tmp17_ = mCompCoord[20];
   double tmp18_ = mCompCoord[17];
   double tmp19_ = tmp17_-tmp18_;
   double tmp20_ = tmp4_*tmp2_;
   double tmp21_ = tmp20_*(tmp9_);
   double tmp22_ = tmp3_*tmp2_;
   double tmp23_ = tmp22_*(tmp16_);
   double tmp24_ = tmp21_+tmp23_;
   double tmp25_ = tmp5_*(tmp19_);
   double tmp26_ = tmp24_+tmp25_;
   double tmp27_ = mCompCoord[0];
   double tmp28_ = -(tmp3_);
   double tmp29_ = tmp28_*tmp11_;
   double tmp30_ = tmp4_*tmp12_;
   double tmp31_ = tmp30_*tmp13_;
   double tmp32_ = tmp29_+tmp31_;
   double tmp33_ = (tmp32_)*(tmp9_);
   double tmp34_ = tmp4_*tmp11_;
   double tmp35_ = tmp3_*tmp12_;
   double tmp36_ = tmp35_*tmp13_;
   double tmp37_ = tmp34_+tmp36_;
   double tmp38_ = (tmp37_)*(tmp16_);
   double tmp39_ = tmp33_+tmp38_;
   double tmp40_ = tmp2_*tmp13_;
   double tmp41_ = tmp40_*(tmp19_);
   double tmp42_ = tmp39_+tmp41_;
   double tmp43_ = tmp27_/(tmp42_);
   double tmp44_ = (tmp26_)*(tmp43_);
   double tmp45_ = mCompCoord[1];
   double tmp46_ = tmp44_+tmp45_;
   double tmp47_ = (tmp46_)-tmp45_;
   double tmp48_ = mCompCoord[2];
   double tmp49_ = tmp28_*tmp13_;
   double tmp50_ = tmp30_*tmp10_;
   double tmp51_ = tmp49_+tmp50_;
   double tmp52_ = (tmp51_)*(tmp9_);
   double tmp53_ = tmp4_*tmp13_;
   double tmp54_ = tmp35_*tmp10_;
   double tmp55_ = tmp53_+tmp54_;
   double tmp56_ = (tmp55_)*(tmp16_);
   double tmp57_ = tmp52_+tmp56_;
   double tmp58_ = tmp2_*tmp10_;
   double tmp59_ = tmp58_*(tmp19_);
   double tmp60_ = tmp57_+tmp59_;
   double tmp61_ = (tmp60_)*(tmp43_);
   double tmp62_ = tmp61_+tmp48_;
   double tmp63_ = (tmp62_)-tmp48_;
   double tmp64_ = (tmp47_)*(tmp47_);
   double tmp65_ = (tmp63_)*(tmp63_);
   double tmp66_ = tmp64_+tmp65_;
   double tmp67_ = (tmp66_)*(tmp66_);
   double tmp68_ = tmp67_*(tmp66_);
   double tmp69_ = tmp68_*(tmp66_);
   double tmp70_ = mCompCoord[3];
   double tmp71_ = tmp70_*(tmp66_);
   double tmp72_ = mCompCoord[4];
   double tmp73_ = tmp72_*tmp67_;
   double tmp74_ = tmp71_+tmp73_;
   double tmp75_ = mCompCoord[5];
   double tmp76_ = tmp75_*tmp68_;
   double tmp77_ = tmp74_+tmp76_;
   double tmp78_ = mCompCoord[6];
   double tmp79_ = tmp78_*tmp69_;
   double tmp80_ = tmp77_+tmp79_;
   double tmp81_ = mCompCoord[7];
   double tmp82_ = tmp69_*(tmp66_);
   double tmp83_ = tmp81_*tmp82_;
   double tmp84_ = tmp80_+tmp83_;
   double tmp85_ = mCompCoord[9];
   double tmp86_ = (tmp47_)*(tmp63_);
   double tmp87_ = 2*tmp86_;
   double tmp88_ = mCompCoord[8];

  mVal[0] = ((tmp46_+(tmp47_)*(tmp84_)+(2*tmp64_+tmp66_)*tmp88_+tmp87_*tmp85_+mCompCoord[10]*(tmp47_)+mCompCoord[11]*(tmp63_))-mLocXIm)*mLocScNorm;

  mVal[1] = ((tmp62_+(tmp63_)*(tmp84_)+(2*tmp65_+tmp66_)*tmp85_+tmp87_*tmp88_)-mLocYIm)*mLocScNorm;

}


void cEqAppui_PTInc_M2CFraser_PPaEqPPs::ComputeValDeriv()
{
   double tmp0_ = mCompCoord[12];
   double tmp1_ = mCompCoord[13];
   double tmp2_ = cos(tmp1_);
   double tmp3_ = sin(tmp0_);
   double tmp4_ = cos(tmp0_);
   double tmp5_ = sin(tmp1_);
   double tmp6_ = mCompCoord[14];
   double tmp7_ = mCompCoord[18];
   double tmp8_ = mCompCoord[15];
   double tmp9_ = tmp7_-tmp8_;
   double tmp10_ = sin(tmp6_);
   double tmp11_ = -(tmp10_);
   double tmp12_ = -(tmp5_);
   double tmp13_ = cos(tmp6_);
   double tmp14_ = mCompCoord[19];
   double tmp15_ = mCompCoord[16];
   double tmp16_ = tmp14_-tmp15_;
   double tmp17_ = mCompCoord[20];
   double tmp18_ = mCompCoord[17];
   double tmp19_ = tmp17_-tmp18_;
   double tmp20_ = tmp4_*tmp2_;
   double tmp21_ = tmp20_*(tmp9_);
   double tmp22_ = tmp3_*tmp2_;
   double tmp23_ = tmp22_*(tmp16_);
   double tmp24_ = tmp21_+tmp23_;
   double tmp25_ = tmp5_*(tmp19_);
   double tmp26_ = tmp24_+tmp25_;
   double tmp27_ = mCompCoord[0];
   double tmp28_ = -(tmp3_);
   double tmp29_ = tmp28_*tmp11_;
   double tmp30_ = tmp4_*tmp12_;
   double tmp31_ = tmp30_*tmp13_;
   double tmp32_ = tmp29_+tmp31_;
   double tmp33_ = (tmp32_)*(tmp9_);
   double tmp34_ = tmp4_*tmp11_;
   double tmp35_ = tmp3_*tmp12_;
   double tmp36_ = tmp35_*tmp13_;
   double tmp37_ = tmp34_+tmp36_;
   double tmp38_ = (tmp37_)*(tmp16_);
   double tmp39_ = tmp33_+tmp38_;
   double tmp40_ = tmp2_*tmp13_;
   double tmp41_ = tmp40_*(tmp19_);
   double tmp42_ = tmp39_+tmp41_;
   double tmp43_ = tmp27_/(tmp42_);
   double tmp44_ = (tmp26_)*(tmp43_);
   double tmp45_ = mCompCoord[1];
   double tmp46_ = tmp44_+tmp45_;
   double tmp47_ = (tmp46_)-tmp45_;
   double tmp48_ = mCompCoord[2];
   double tmp49_ = tmp28_*tmp13_;
   double tmp50_ = tmp30_*tmp10_;
   double tmp51_ = tmp49_+tmp50_;
   double tmp52_ = (tmp51_)*(tmp9_);
   double tmp53_ = tmp4_*tmp13_;
   double tmp54_ = tmp35_*tmp10_;
   double tmp55_ = tmp53_+tmp54_;
   double tmp56_ = (tmp55_)*(tmp16_);
   double tmp57_ = tmp52_+tmp56_;
   double tmp58_ = tmp2_*tmp10_;
   double tmp59_ = tmp58_*(tmp19_);
   double tmp60_ = tmp57_+tmp59_;
   double tmp61_ = (tmp60_)*(tmp43_);
   double tmp62_ = tmp61_+tmp48_;
   double tmp63_ = (tmp62_)-tmp48_;
   double tmp64_ = (tmp47_)*(tmp47_);
   double tmp65_ = (tmp63_)*(tmp63_);
   double tmp66_ = tmp64_+tmp65_;
   double tmp67_ = (tmp66_)*(tmp66_);
   double tmp68_ = tmp67_*(tmp66_);
   double tmp69_ = tmp68_*(tmp66_);
   double tmp70_ = ElSquare(tmp42_);
   double tmp71_ = (tmp42_)/tmp70_;
   double tmp72_ = (tmp71_)*(tmp26_);
   double tmp73_ = mCompCoord[3];
   double tmp74_ = tmp73_*(tmp66_);
   double tmp75_ = mCompCoord[4];
   double tmp76_ = tmp75_*tmp67_;
   double tmp77_ = tmp74_+tmp76_;
   double tmp78_ = mCompCoord[5];
   double tmp79_ = tmp78_*tmp68_;
   double tmp80_ = tmp77_+tmp79_;
   double tmp81_ = mCompCoord[6];
   double tmp82_ = tmp81_*tmp69_;
   double tmp83_ = tmp80_+tmp82_;
   double tmp84_ = mCompCoord[7];
   double tmp85_ = tmp69_*(tmp66_);
   double tmp86_ = tmp84_*tmp85_;
   double tmp87_ = tmp83_+tmp86_;
   double tmp88_ = tmp72_*(tmp47_);
   double tmp89_ = (tmp71_)*(tmp60_);
   double tmp90_ = tmp89_*(tmp63_);
   double tmp91_ = tmp88_+tmp88_;
   double tmp92_ = tmp90_+tmp90_;
   double tmp93_ = tmp91_+tmp92_;
   double tmp94_ = (tmp93_)*(tmp66_);
   double tmp95_ = tmp94_+tmp94_;
   double tmp96_ = (tmp95_)*(tmp66_);
   double tmp97_ = (tmp93_)*tmp67_;
   double tmp98_ = tmp96_+tmp97_;
   double tmp99_ = (tmp98_)*(tmp66_);
   double tmp100_ = (tmp93_)*tmp68_;
   double tmp101_ = tmp99_+tmp100_;
   double tmp102_ = mCompCoord[8];
   double tmp103_ = mCompCoord[9];
   double tmp104_ = mCompCoord[10];
   double tmp105_ = mCompCoord[11];
   double tmp106_ = 2*tmp64_;
   double tmp107_ = tmp106_+tmp66_;
   double tmp108_ = (tmp47_)*(tmp63_);
   double tmp109_ = 2*tmp108_;
   double tmp110_ = -(1);
   double tmp111_ = tmp110_*tmp3_;
   double tmp112_ = tmp111_*tmp2_;
   double tmp113_ = tmp112_*(tmp9_);
   double tmp114_ = tmp20_*(tmp16_);
   double tmp115_ = tmp113_+tmp114_;
   double tmp116_ = (tmp115_)*(tmp43_);
   double tmp117_ = -(tmp4_);
   double tmp118_ = tmp117_*tmp11_;
   double tmp119_ = tmp111_*tmp12_;
   double tmp120_ = tmp119_*tmp13_;
   double tmp121_ = tmp118_+tmp120_;
   double tmp122_ = (tmp121_)*(tmp9_);
   double tmp123_ = tmp111_*tmp11_;
   double tmp124_ = tmp123_+tmp31_;
   double tmp125_ = (tmp124_)*(tmp16_);
   double tmp126_ = tmp122_+tmp125_;
   double tmp127_ = tmp27_*(tmp126_);
   double tmp128_ = -(tmp127_);
   double tmp129_ = tmp128_/tmp70_;
   double tmp130_ = (tmp129_)*(tmp26_);
   double tmp131_ = tmp116_+tmp130_;
   double tmp132_ = (tmp131_)*(tmp47_);
   double tmp133_ = tmp117_*tmp13_;
   double tmp134_ = tmp119_*tmp10_;
   double tmp135_ = tmp133_+tmp134_;
   double tmp136_ = (tmp135_)*(tmp9_);
   double tmp137_ = tmp111_*tmp13_;
   double tmp138_ = tmp137_+tmp50_;
   double tmp139_ = (tmp138_)*(tmp16_);
   double tmp140_ = tmp136_+tmp139_;
   double tmp141_ = (tmp140_)*(tmp43_);
   double tmp142_ = (tmp129_)*(tmp60_);
   double tmp143_ = tmp141_+tmp142_;
   double tmp144_ = (tmp143_)*(tmp63_);
   double tmp145_ = tmp132_+tmp132_;
   double tmp146_ = tmp144_+tmp144_;
   double tmp147_ = tmp145_+tmp146_;
   double tmp148_ = (tmp147_)*(tmp66_);
   double tmp149_ = tmp148_+tmp148_;
   double tmp150_ = (tmp149_)*(tmp66_);
   double tmp151_ = (tmp147_)*tmp67_;
   double tmp152_ = tmp150_+tmp151_;
   double tmp153_ = (tmp152_)*(tmp66_);
   double tmp154_ = (tmp147_)*tmp68_;
   double tmp155_ = tmp153_+tmp154_;
   double tmp156_ = tmp110_*tmp5_;
   double tmp157_ = -(tmp2_);
   double tmp158_ = tmp156_*tmp4_;
   double tmp159_ = tmp158_*(tmp9_);
   double tmp160_ = tmp156_*tmp3_;
   double tmp161_ = tmp160_*(tmp16_);
   double tmp162_ = tmp159_+tmp161_;
   double tmp163_ = tmp2_*(tmp19_);
   double tmp164_ = tmp162_+tmp163_;
   double tmp165_ = (tmp164_)*(tmp43_);
   double tmp166_ = tmp157_*tmp4_;
   double tmp167_ = tmp166_*tmp13_;
   double tmp168_ = tmp167_*(tmp9_);
   double tmp169_ = tmp157_*tmp3_;
   double tmp170_ = tmp169_*tmp13_;
   double tmp171_ = tmp170_*(tmp16_);
   double tmp172_ = tmp168_+tmp171_;
   double tmp173_ = tmp156_*tmp13_;
   double tmp174_ = tmp173_*(tmp19_);
   double tmp175_ = tmp172_+tmp174_;
   double tmp176_ = tmp27_*(tmp175_);
   double tmp177_ = -(tmp176_);
   double tmp178_ = tmp177_/tmp70_;
   double tmp179_ = (tmp178_)*(tmp26_);
   double tmp180_ = tmp165_+tmp179_;
   double tmp181_ = (tmp180_)*(tmp47_);
   double tmp182_ = tmp166_*tmp10_;
   double tmp183_ = tmp182_*(tmp9_);
   double tmp184_ = tmp169_*tmp10_;
   double tmp185_ = tmp184_*(tmp16_);
   double tmp186_ = tmp183_+tmp185_;
   double tmp187_ = tmp156_*tmp10_;
   double tmp188_ = tmp187_*(tmp19_);
   double tmp189_ = tmp186_+tmp188_;
   double tmp190_ = (tmp189_)*(tmp43_);
   double tmp191_ = (tmp178_)*(tmp60_);
   double tmp192_ = tmp190_+tmp191_;
   double tmp193_ = (tmp192_)*(tmp63_);
   double tmp194_ = tmp181_+tmp181_;
   double tmp195_ = tmp193_+tmp193_;
   double tmp196_ = tmp194_+tmp195_;
   double tmp197_ = (tmp196_)*(tmp66_);
   double tmp198_ = tmp197_+tmp197_;
   double tmp199_ = (tmp198_)*(tmp66_);
   double tmp200_ = (tmp196_)*tmp67_;
   double tmp201_ = tmp199_+tmp200_;
   double tmp202_ = (tmp201_)*(tmp66_);
   double tmp203_ = (tmp196_)*tmp68_;
   double tmp204_ = tmp202_+tmp203_;
   double tmp205_ = -(tmp13_);
   double tmp206_ = tmp110_*tmp10_;
   double tmp207_ = tmp205_*tmp28_;
   double tmp208_ = tmp206_*tmp30_;
   double tmp209_ = tmp207_+tmp208_;
   double tmp210_ = (tmp209_)*(tmp9_);
   double tmp211_ = tmp205_*tmp4_;
   double tmp212_ = tmp206_*tmp35_;
   double tmp213_ = tmp211_+tmp212_;
   double tmp214_ = (tmp213_)*(tmp16_);
   double tmp215_ = tmp210_+tmp214_;
   double tmp216_ = tmp206_*tmp2_;
   double tmp217_ = tmp216_*(tmp19_);
   double tmp218_ = tmp215_+tmp217_;
   double tmp219_ = tmp27_*(tmp218_);
   double tmp220_ = -(tmp219_);
   double tmp221_ = tmp220_/tmp70_;
   double tmp222_ = (tmp221_)*(tmp26_);
   double tmp223_ = tmp222_*(tmp47_);
   double tmp224_ = tmp206_*tmp28_;
   double tmp225_ = tmp13_*tmp30_;
   double tmp226_ = tmp224_+tmp225_;
   double tmp227_ = (tmp226_)*(tmp9_);
   double tmp228_ = tmp206_*tmp4_;
   double tmp229_ = tmp13_*tmp35_;
   double tmp230_ = tmp228_+tmp229_;
   double tmp231_ = (tmp230_)*(tmp16_);
   double tmp232_ = tmp227_+tmp231_;
   double tmp233_ = tmp13_*tmp2_;
   double tmp234_ = tmp233_*(tmp19_);
   double tmp235_ = tmp232_+tmp234_;
   double tmp236_ = (tmp235_)*(tmp43_);
   double tmp237_ = (tmp221_)*(tmp60_);
   double tmp238_ = tmp236_+tmp237_;
   double tmp239_ = (tmp238_)*(tmp63_);
   double tmp240_ = tmp223_+tmp223_;
   double tmp241_ = tmp239_+tmp239_;
   double tmp242_ = tmp240_+tmp241_;
   double tmp243_ = (tmp242_)*(tmp66_);
   double tmp244_ = tmp243_+tmp243_;
   double tmp245_ = (tmp244_)*(tmp66_);
   double tmp246_ = (tmp242_)*tmp67_;
   double tmp247_ = tmp245_+tmp246_;
   double tmp248_ = (tmp247_)*(tmp66_);
   double tmp249_ = (tmp242_)*tmp68_;
   double tmp250_ = tmp248_+tmp249_;
   double tmp251_ = tmp110_*tmp20_;
   double tmp252_ = tmp251_*(tmp43_);
   double tmp253_ = tmp110_*(tmp32_);
   double tmp254_ = tmp27_*tmp253_;
   double tmp255_ = -(tmp254_);
   double tmp256_ = tmp255_/tmp70_;
   double tmp257_ = (tmp256_)*(tmp26_);
   double tmp258_ = tmp252_+tmp257_;
   double tmp259_ = (tmp258_)*(tmp47_);
   double tmp260_ = tmp110_*(tmp51_);
   double tmp261_ = tmp260_*(tmp43_);
   double tmp262_ = (tmp256_)*(tmp60_);
   double tmp263_ = tmp261_+tmp262_;
   double tmp264_ = (tmp263_)*(tmp63_);
   double tmp265_ = tmp259_+tmp259_;
   double tmp266_ = tmp264_+tmp264_;
   double tmp267_ = tmp265_+tmp266_;
   double tmp268_ = (tmp267_)*(tmp66_);
   double tmp269_ = tmp268_+tmp268_;
   double tmp270_ = (tmp269_)*(tmp66_);
   double tmp271_ = (tmp267_)*tmp67_;
   double tmp272_ = tmp270_+tmp271_;
   double tmp273_ = (tmp272_)*(tmp66_);
   double tmp274_ = (tmp267_)*tmp68_;
   double tmp275_ = tmp273_+tmp274_;
   double tmp276_ = tmp110_*tmp22_;
   double tmp277_ = tmp276_*(tmp43_);
   double tmp278_ = tmp110_*(tmp37_);
   double tmp279_ = tmp27_*tmp278_;
   double tmp280_ = -(tmp279_);
   double tmp281_ = tmp280_/tmp70_;
   double tmp282_ = (tmp281_)*(tmp26_);
   double tmp283_ = tmp277_+tmp282_;
   double tmp284_ = (tmp283_)*(tmp47_);
   double tmp285_ = tmp110_*(tmp55_);
   double tmp286_ = tmp285_*(tmp43_);
   double tmp287_ = (tmp281_)*(tmp60_);
   double tmp288_ = tmp286_+tmp287_;
   double tmp289_ = (tmp288_)*(tmp63_);
   double tmp290_ = tmp284_+tmp284_;
   double tmp291_ = tmp289_+tmp289_;
   double tmp292_ = tmp290_+tmp291_;
   double tmp293_ = (tmp292_)*(tmp66_);
   double tmp294_ = tmp293_+tmp293_;
   double tmp295_ = (tmp294_)*(tmp66_);
   double tmp296_ = (tmp292_)*tmp67_;
   double tmp297_ = tmp295_+tmp296_;
   double tmp298_ = (tmp297_)*(tmp66_);
   double tmp299_ = (tmp292_)*tmp68_;
   double tmp300_ = tmp298_+tmp299_;
   double tmp301_ = tmp156_*(tmp43_);
   double tmp302_ = tmp110_*tmp40_;
   double tmp303_ = tmp27_*tmp302_;
   double tmp304_ = -(tmp303_);
   double tmp305_ = tmp304_/tmp70_;
   double tmp306_ = (tmp305_)*(tmp26_);
   double tmp307_ = tmp301_+tmp306_;
   double tmp308_ = (tmp307_)*(tmp47_);
   double tmp309_ = tmp110_*tmp58_;
   double tmp310_ = tmp309_*(tmp43_);
   double tmp311_ = (tmp305_)*(tmp60_);
   double tmp312_ = tmp310_+tmp311_;
   double tmp313_ = (tmp312_)*(tmp63_);
   double tmp314_ = tmp308_+tmp308_;
   double tmp315_ = tmp313_+tmp313_;
   double tmp316_ = tmp314_+tmp315_;
   double tmp317_ = (tmp316_)*(tmp66_);
   double tmp318_ = tmp317_+tmp317_;
   double tmp319_ = (tmp318_)*(tmp66_);
   double tmp320_ = (tmp316_)*tmp67_;
   double tmp321_ = tmp319_+tmp320_;
   double tmp322_ = (tmp321_)*(tmp66_);
   double tmp323_ = (tmp316_)*tmp68_;
   double tmp324_ = tmp322_+tmp323_;
   double tmp325_ = tmp20_*(tmp43_);
   double tmp326_ = tmp27_*(tmp32_);
   double tmp327_ = -(tmp326_);
   double tmp328_ = tmp327_/tmp70_;
   double tmp329_ = (tmp328_)*(tmp26_);
   double tmp330_ = tmp325_+tmp329_;
   double tmp331_ = (tmp330_)*(tmp47_);
   double tmp332_ = (tmp51_)*(tmp43_);
   double tmp333_ = (tmp328_)*(tmp60_);
   double tmp334_ = tmp332_+tmp333_;
   double tmp335_ = (tmp334_)*(tmp63_);
   double tmp336_ = tmp331_+tmp331_;
   double tmp337_ = tmp335_+tmp335_;
   double tmp338_ = tmp336_+tmp337_;
   double tmp339_ = (tmp338_)*(tmp66_);
   double tmp340_ = tmp339_+tmp339_;
   double tmp341_ = (tmp340_)*(tmp66_);
   double tmp342_ = (tmp338_)*tmp67_;
   double tmp343_ = tmp341_+tmp342_;
   double tmp344_ = (tmp343_)*(tmp66_);
   double tmp345_ = (tmp338_)*tmp68_;
   double tmp346_ = tmp344_+tmp345_;
   double tmp347_ = tmp22_*(tmp43_);
   double tmp348_ = tmp27_*(tmp37_);
   double tmp349_ = -(tmp348_);
   double tmp350_ = tmp349_/tmp70_;
   double tmp351_ = (tmp350_)*(tmp26_);
   double tmp352_ = tmp347_+tmp351_;
   double tmp353_ = (tmp352_)*(tmp47_);
   double tmp354_ = (tmp55_)*(tmp43_);
   double tmp355_ = (tmp350_)*(tmp60_);
   double tmp356_ = tmp354_+tmp355_;
   double tmp357_ = (tmp356_)*(tmp63_);
   double tmp358_ = tmp353_+tmp353_;
   double tmp359_ = tmp357_+tmp357_;
   double tmp360_ = tmp358_+tmp359_;
   double tmp361_ = (tmp360_)*(tmp66_);
   double tmp362_ = tmp361_+tmp361_;
   double tmp363_ = (tmp362_)*(tmp66_);
   double tmp364_ = (tmp360_)*tmp67_;
   double tmp365_ = tmp363_+tmp364_;
   double tmp366_ = (tmp365_)*(tmp66_);
   double tmp367_ = (tmp360_)*tmp68_;
   double tmp368_ = tmp366_+tmp367_;
   double tmp369_ = tmp5_*(tmp43_);
   double tmp370_ = tmp27_*tmp40_;
   double tmp371_ = -(tmp370_);
   double tmp372_ = tmp371_/tmp70_;
   double tmp373_ = (tmp372_)*(tmp26_);
   double tmp374_ = tmp369_+tmp373_;
   double tmp375_ = (tmp374_)*(tmp47_);
   double tmp376_ = tmp58_*(tmp43_);
   double tmp377_ = (tmp372_)*(tmp60_);
   double tmp378_ = tmp376_+tmp377_;
   double tmp379_ = (tmp378_)*(tmp63_);
   double tmp380_ = tmp375_+tmp375_;
   double tmp381_ = tmp379_+tmp379_;
   double tmp382_ = tmp380_+tmp381_;
   double tmp383_ = (tmp382_)*(tmp66_);
   double tmp384_ = tmp383_+tmp383_;
   double tmp385_ = (tmp384_)*(tmp66_);
   double tmp386_ = (tmp382_)*tmp67_;
   double tmp387_ = tmp385_+tmp386_;
   double tmp388_ = (tmp387_)*(tmp66_);
   double tmp389_ = (tmp382_)*tmp68_;
   double tmp390_ = tmp388_+tmp389_;
   double tmp391_ = (tmp93_)*tmp73_;
   double tmp392_ = (tmp95_)*tmp75_;
   double tmp393_ = tmp391_+tmp392_;
   double tmp394_ = (tmp98_)*tmp78_;
   double tmp395_ = tmp393_+tmp394_;
   double tmp396_ = (tmp101_)*tmp81_;
   double tmp397_ = tmp395_+tmp396_;
   double tmp398_ = (tmp101_)*(tmp66_);
   double tmp399_ = (tmp93_)*tmp69_;
   double tmp400_ = tmp398_+tmp399_;
   double tmp401_ = (tmp400_)*tmp84_;
   double tmp402_ = tmp397_+tmp401_;
   double tmp403_ = tmp72_*(tmp63_);
   double tmp404_ = tmp89_*(tmp47_);
   double tmp405_ = tmp403_+tmp404_;
   double tmp406_ = (tmp405_)*2;
   double tmp407_ = tmp109_*mLocScNorm;
   double tmp408_ = 2*tmp65_;
   double tmp409_ = tmp408_+tmp66_;
   double tmp410_ = (tmp147_)*tmp73_;
   double tmp411_ = (tmp149_)*tmp75_;
   double tmp412_ = tmp410_+tmp411_;
   double tmp413_ = (tmp152_)*tmp78_;
   double tmp414_ = tmp412_+tmp413_;
   double tmp415_ = (tmp155_)*tmp81_;
   double tmp416_ = tmp414_+tmp415_;
   double tmp417_ = (tmp155_)*(tmp66_);
   double tmp418_ = (tmp147_)*tmp69_;
   double tmp419_ = tmp417_+tmp418_;
   double tmp420_ = (tmp419_)*tmp84_;
   double tmp421_ = tmp416_+tmp420_;
   double tmp422_ = (tmp131_)*(tmp63_);
   double tmp423_ = (tmp143_)*(tmp47_);
   double tmp424_ = tmp422_+tmp423_;
   double tmp425_ = (tmp424_)*2;
   double tmp426_ = (tmp196_)*tmp73_;
   double tmp427_ = (tmp198_)*tmp75_;
   double tmp428_ = tmp426_+tmp427_;
   double tmp429_ = (tmp201_)*tmp78_;
   double tmp430_ = tmp428_+tmp429_;
   double tmp431_ = (tmp204_)*tmp81_;
   double tmp432_ = tmp430_+tmp431_;
   double tmp433_ = (tmp204_)*(tmp66_);
   double tmp434_ = (tmp196_)*tmp69_;
   double tmp435_ = tmp433_+tmp434_;
   double tmp436_ = (tmp435_)*tmp84_;
   double tmp437_ = tmp432_+tmp436_;
   double tmp438_ = (tmp180_)*(tmp63_);
   double tmp439_ = (tmp192_)*(tmp47_);
   double tmp440_ = tmp438_+tmp439_;
   double tmp441_ = (tmp440_)*2;
   double tmp442_ = (tmp242_)*tmp73_;
   double tmp443_ = (tmp244_)*tmp75_;
   double tmp444_ = tmp442_+tmp443_;
   double tmp445_ = (tmp247_)*tmp78_;
   double tmp446_ = tmp444_+tmp445_;
   double tmp447_ = (tmp250_)*tmp81_;
   double tmp448_ = tmp446_+tmp447_;
   double tmp449_ = (tmp250_)*(tmp66_);
   double tmp450_ = (tmp242_)*tmp69_;
   double tmp451_ = tmp449_+tmp450_;
   double tmp452_ = (tmp451_)*tmp84_;
   double tmp453_ = tmp448_+tmp452_;
   double tmp454_ = tmp222_*(tmp63_);
   double tmp455_ = (tmp238_)*(tmp47_);
   double tmp456_ = tmp454_+tmp455_;
   double tmp457_ = (tmp456_)*2;
   double tmp458_ = (tmp267_)*tmp73_;
   double tmp459_ = (tmp269_)*tmp75_;
   double tmp460_ = tmp458_+tmp459_;
   double tmp461_ = (tmp272_)*tmp78_;
   double tmp462_ = tmp460_+tmp461_;
   double tmp463_ = (tmp275_)*tmp81_;
   double tmp464_ = tmp462_+tmp463_;
   double tmp465_ = (tmp275_)*(tmp66_);
   double tmp466_ = (tmp267_)*tmp69_;
   double tmp467_ = tmp465_+tmp466_;
   double tmp468_ = (tmp467_)*tmp84_;
   double tmp469_ = tmp464_+tmp468_;
   double tmp470_ = (tmp258_)*(tmp63_);
   double tmp471_ = (tmp263_)*(tmp47_);
   double tmp472_ = tmp470_+tmp471_;
   double tmp473_ = (tmp472_)*2;
   double tmp474_ = (tmp292_)*tmp73_;
   double tmp475_ = (tmp294_)*tmp75_;
   double tmp476_ = tmp474_+tmp475_;
   double tmp477_ = (tmp297_)*tmp78_;
   double tmp478_ = tmp476_+tmp477_;
   double tmp479_ = (tmp300_)*tmp81_;
   double tmp480_ = tmp478_+tmp479_;
   double tmp481_ = (tmp300_)*(tmp66_);
   double tmp482_ = (tmp292_)*tmp69_;
   double tmp483_ = tmp481_+tmp482_;
   double tmp484_ = (tmp483_)*tmp84_;
   double tmp485_ = tmp480_+tmp484_;
   double tmp486_ = (tmp283_)*(tmp63_);
   double tmp487_ = (tmp288_)*(tmp47_);
   double tmp488_ = tmp486_+tmp487_;
   double tmp489_ = (tmp488_)*2;
   double tmp490_ = (tmp316_)*tmp73_;
   double tmp491_ = (tmp318_)*tmp75_;
   double tmp492_ = tmp490_+tmp491_;
   double tmp493_ = (tmp321_)*tmp78_;
   double tmp494_ = tmp492_+tmp493_;
   double tmp495_ = (tmp324_)*tmp81_;
   double tmp496_ = tmp494_+tmp495_;
   double tmp497_ = (tmp324_)*(tmp66_);
   double tmp498_ = (tmp316_)*tmp69_;
   double tmp499_ = tmp497_+tmp498_;
   double tmp500_ = (tmp499_)*tmp84_;
   double tmp501_ = tmp496_+tmp500_;
   double tmp502_ = (tmp307_)*(tmp63_);
   double tmp503_ = (tmp312_)*(tmp47_);
   double tmp504_ = tmp502_+tmp503_;
   double tmp505_ = (tmp504_)*2;
   double tmp506_ = (tmp338_)*tmp73_;
   double tmp507_ = (tmp340_)*tmp75_;
   double tmp508_ = tmp506_+tmp507_;
   double tmp509_ = (tmp343_)*tmp78_;
   double tmp510_ = tmp508_+tmp509_;
   double tmp511_ = (tmp346_)*tmp81_;
   double tmp512_ = tmp510_+tmp511_;
   double tmp513_ = (tmp346_)*(tmp66_);
   double tmp514_ = (tmp338_)*tmp69_;
   double tmp515_ = tmp513_+tmp514_;
   double tmp516_ = (tmp515_)*tmp84_;
   double tmp517_ = tmp512_+tmp516_;
   double tmp518_ = (tmp330_)*(tmp63_);
   double tmp519_ = (tmp334_)*(tmp47_);
   double tmp520_ = tmp518_+tmp519_;
   double tmp521_ = (tmp520_)*2;
   double tmp522_ = (tmp360_)*tmp73_;
   double tmp523_ = (tmp362_)*tmp75_;
   double tmp524_ = tmp522_+tmp523_;
   double tmp525_ = (tmp365_)*tmp78_;
   double tmp526_ = tmp524_+tmp525_;
   double tmp527_ = (tmp368_)*tmp81_;
   double tmp528_ = tmp526_+tmp527_;
   double tmp529_ = (tmp368_)*(tmp66_);
   double tmp530_ = (tmp360_)*tmp69_;
   double tmp531_ = tmp529_+tmp530_;
   double tmp532_ = (tmp531_)*tmp84_;
   double tmp533_ = tmp528_+tmp532_;
   double tmp534_ = (tmp352_)*(tmp63_);
   double tmp535_ = (tmp356_)*(tmp47_);
   double tmp536_ = tmp534_+tmp535_;
   double tmp537_ = (tmp536_)*2;
   double tmp538_ = (tmp382_)*tmp73_;
   double tmp539_ = (tmp384_)*tmp75_;
   double tmp540_ = tmp538_+tmp539_;
   double tmp541_ = (tmp387_)*tmp78_;
   double tmp542_ = tmp540_+tmp541_;
   double tmp543_ = (tmp390_)*tmp81_;
   double tmp544_ = tmp542_+tmp543_;
   double tmp545_ = (tmp390_)*(tmp66_);
   double tmp546_ = (tmp382_)*tmp69_;
   double tmp547_ = tmp545_+tmp546_;
   double tmp548_ = (tmp547_)*tmp84_;
   double tmp549_ = tmp544_+tmp548_;
   double tmp550_ = (tmp374_)*(tmp63_);
   double tmp551_ = (tmp378_)*(tmp47_);
   double tmp552_ = tmp550_+tmp551_;
   double tmp553_ = (tmp552_)*2;

  mVal[0] = ((tmp46_+(tmp47_)*(tmp87_)+(tmp107_)*tmp102_+tmp109_*tmp103_+tmp104_*(tmp47_)+tmp105_*(tmp63_))-mLocXIm)*mLocScNorm;

  mCompDer[0][0] = (tmp72_+tmp72_*(tmp87_)+(tmp402_)*(tmp47_)+((tmp91_)*2+tmp93_)*tmp102_+tmp406_*tmp103_+tmp72_*tmp104_+tmp89_*tmp105_)*mLocScNorm;
  mCompDer[0][1] = mLocScNorm;
  mCompDer[0][2] = 0;
  mCompDer[0][3] = (tmp66_)*(tmp47_)*mLocScNorm;
  mCompDer[0][4] = tmp67_*(tmp47_)*mLocScNorm;
  mCompDer[0][5] = tmp68_*(tmp47_)*mLocScNorm;
  mCompDer[0][6] = tmp69_*(tmp47_)*mLocScNorm;
  mCompDer[0][7] = tmp85_*(tmp47_)*mLocScNorm;
  mCompDer[0][8] = (tmp107_)*mLocScNorm;
  mCompDer[0][9] = tmp407_;
  mCompDer[0][10] = (tmp47_)*mLocScNorm;
  mCompDer[0][11] = (tmp63_)*mLocScNorm;
  mCompDer[0][12] = (tmp131_+(tmp131_)*(tmp87_)+(tmp421_)*(tmp47_)+((tmp145_)*2+tmp147_)*tmp102_+tmp425_*tmp103_+(tmp131_)*tmp104_+(tmp143_)*tmp105_)*mLocScNorm;
  mCompDer[0][13] = (tmp180_+(tmp180_)*(tmp87_)+(tmp437_)*(tmp47_)+((tmp194_)*2+tmp196_)*tmp102_+tmp441_*tmp103_+(tmp180_)*tmp104_+(tmp192_)*tmp105_)*mLocScNorm;
  mCompDer[0][14] = (tmp222_+tmp222_*(tmp87_)+(tmp453_)*(tmp47_)+((tmp240_)*2+tmp242_)*tmp102_+tmp457_*tmp103_+tmp222_*tmp104_+(tmp238_)*tmp105_)*mLocScNorm;
  mCompDer[0][15] = (tmp258_+(tmp258_)*(tmp87_)+(tmp469_)*(tmp47_)+((tmp265_)*2+tmp267_)*tmp102_+tmp473_*tmp103_+(tmp258_)*tmp104_+(tmp263_)*tmp105_)*mLocScNorm;
  mCompDer[0][16] = (tmp283_+(tmp283_)*(tmp87_)+(tmp485_)*(tmp47_)+((tmp290_)*2+tmp292_)*tmp102_+tmp489_*tmp103_+(tmp283_)*tmp104_+(tmp288_)*tmp105_)*mLocScNorm;
  mCompDer[0][17] = (tmp307_+(tmp307_)*(tmp87_)+(tmp501_)*(tmp47_)+((tmp314_)*2+tmp316_)*tmp102_+tmp505_*tmp103_+(tmp307_)*tmp104_+(tmp312_)*tmp105_)*mLocScNorm;
  mCompDer[0][18] = (tmp330_+(tmp330_)*(tmp87_)+(tmp517_)*(tmp47_)+((tmp336_)*2+tmp338_)*tmp102_+tmp521_*tmp103_+(tmp330_)*tmp104_+(tmp334_)*tmp105_)*mLocScNorm;
  mCompDer[0][19] = (tmp352_+(tmp352_)*(tmp87_)+(tmp533_)*(tmp47_)+((tmp358_)*2+tmp360_)*tmp102_+tmp537_*tmp103_+(tmp352_)*tmp104_+(tmp356_)*tmp105_)*mLocScNorm;
  mCompDer[0][20] = (tmp374_+(tmp374_)*(tmp87_)+(tmp549_)*(tmp47_)+((tmp380_)*2+tmp382_)*tmp102_+tmp553_*tmp103_+(tmp374_)*tmp104_+(tmp378_)*tmp105_)*mLocScNorm;
  mVal[1] = ((tmp62_+(tmp63_)*(tmp87_)+(tmp409_)*tmp103_+tmp109_*tmp102_)-mLocYIm)*mLocScNorm;

  mCompDer[1][0] = (tmp89_+tmp89_*(tmp87_)+(tmp402_)*(tmp63_)+((tmp92_)*2+tmp93_)*tmp103_+tmp406_*tmp102_)*mLocScNorm;
  mCompDer[1][1] = 0;
  mCompDer[1][2] = mLocScNorm;
  mCompDer[1][3] = (tmp66_)*(tmp63_)*mLocScNorm;
  mCompDer[1][4] = tmp67_*(tmp63_)*mLocScNorm;
  mCompDer[1][5] = tmp68_*(tmp63_)*mLocScNorm;
  mCompDer[1][6] = tmp69_*(tmp63_)*mLocScNorm;
  mCompDer[1][7] = tmp85_*(tmp63_)*mLocScNorm;
  mCompDer[1][8] = tmp407_;
  mCompDer[1][9] = (tmp409_)*mLocScNorm;
  mCompDer[1][10] = 0;
  mCompDer[1][11] = 0;
  mCompDer[1][12] = (tmp143_+(tmp143_)*(tmp87_)+(tmp421_)*(tmp63_)+((tmp146_)*2+tmp147_)*tmp103_+tmp425_*tmp102_)*mLocScNorm;
  mCompDer[1][13] = (tmp192_+(tmp192_)*(tmp87_)+(tmp437_)*(tmp63_)+((tmp195_)*2+tmp196_)*tmp103_+tmp441_*tmp102_)*mLocScNorm;
  mCompDer[1][14] = (tmp238_+(tmp238_)*(tmp87_)+(tmp453_)*(tmp63_)+((tmp241_)*2+tmp242_)*tmp103_+tmp457_*tmp102_)*mLocScNorm;
  mCompDer[1][15] = (tmp263_+(tmp263_)*(tmp87_)+(tmp469_)*(tmp63_)+((tmp266_)*2+tmp267_)*tmp103_+tmp473_*tmp102_)*mLocScNorm;
  mCompDer[1][16] = (tmp288_+(tmp288_)*(tmp87_)+(tmp485_)*(tmp63_)+((tmp291_)*2+tmp292_)*tmp103_+tmp489_*tmp102_)*mLocScNorm;
  mCompDer[1][17] = (tmp312_+(tmp312_)*(tmp87_)+(tmp501_)*(tmp63_)+((tmp315_)*2+tmp316_)*tmp103_+tmp505_*tmp102_)*mLocScNorm;
  mCompDer[1][18] = (tmp334_+(tmp334_)*(tmp87_)+(tmp517_)*(tmp63_)+((tmp337_)*2+tmp338_)*tmp103_+tmp521_*tmp102_)*mLocScNorm;
  mCompDer[1][19] = (tmp356_+(tmp356_)*(tmp87_)+(tmp533_)*(tmp63_)+((tmp359_)*2+tmp360_)*tmp103_+tmp537_*tmp102_)*mLocScNorm;
  mCompDer[1][20] = (tmp378_+(tmp378_)*(tmp87_)+(tmp549_)*(tmp63_)+((tmp381_)*2+tmp382_)*tmp103_+tmp553_*tmp102_)*mLocScNorm;
}


void cEqAppui_PTInc_M2CFraser_PPaEqPPs::ComputeValDerivHessian()
{
  ELISE_ASSERT(false,"Foncteur cEqAppui_PTInc_M2CFraser_PPaEqPPs Has no Der Sec");
}

void cEqAppui_PTInc_M2CFraser_PPaEqPPs::SetScNorm(double aVal){ mLocScNorm = aVal;}
void cEqAppui_PTInc_M2CFraser_PPaEqPPs::SetXIm(double aVal){ mLocXIm = aVal;}
void cEqAppui_PTInc_M2CFraser_PPaEqPPs::SetYIm(double aVal){ mLocYIm = aVal;}



double * cEqAppui_PTInc_M2CFraser_PPaEqPPs::AdrVarLocFromString(const std::string & aName)
{
   if (aName == "ScNorm") return & mLocScNorm;
   if (aName == "XIm") return & mLocXIm;
   if (aName == "YIm") return & mLocYIm;
   return 0;
}


cElCompiledFonc::cAutoAddEntry cEqAppui_PTInc_M2CFraser_PPaEqPPs::mTheAuto("cEqAppui_PTInc_M2CFraser_PPaEqPPs",cEqAppui_PTInc_M2CFraser_PPaEqPPs::Alloc);


cElCompiledFonc *  cEqAppui_PTInc_M2CFraser_PPaEqPPs::Alloc()
{  return new cEqAppui_PTInc_M2CFraser_PPaEqPPs();
}


