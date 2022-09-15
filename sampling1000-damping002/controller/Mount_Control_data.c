/*
 * File: Mount_Control_data.c
 *
 * Code generated for Simulink model 'Mount_Control'.
 *
 * Model version                  : 1.980
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar  9 16:22:21 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Mount_Control.h"
#include "Mount_Control_private.h"

/* Constant parameters (default storage) */
const ConstP_Mount_Control_T Mount_Control_ConstP = {
  /* Computed Parameter: DiscreteSS_A
   * Referenced by: '<S2>/Discrete SS'
   */
  { 1.0, 0.36975394525692207, 0.43077447423346088, 0.10094346809026543,
    -0.24700405618859603, 0.095020608997592654, 0.025628347052125175,
    -0.14236234214985191, -0.020352363086394046, -0.017807623055966715,
    0.032936372652347709, 0.015411026685736287, 0.012666963982998743,
    -0.43077447423345011, -0.10357635332635073, 0.10837673879787954,
    -0.16675374591038247, 0.061184321533605646, -0.005381511015546553,
    -0.082142491615520077, -0.00661398187787049, -0.010408716892378838,
    0.012030716924984603, 0.0076354824133247319, 0.0048497604727126093,
    0.10094346809028058, -0.10837673879787933, 0.92941680288060413,
    0.33151551129497608, -0.021664695449272037, 0.017788151497748671,
    0.013305452718517789, -0.0023049096099459236, 0.00024228795022896986,
    0.0026220392746825962, 8.7628800771288073E-5, 0.00065125057982345328,
    0.24700405618859272, -0.1667537459103747, -0.33151551129497958,
    0.78577108886538727, 0.076534083416687146, 0.086861483233433984,
    -0.093596755060136774, -0.021806407327378447, -0.013950796913079554,
    0.031657653373420622, 0.012016758384292834, 0.01098928406203634,
    -0.095020608997598413, 0.061184321533603786, 0.021664695449274903,
    0.0765340834166915, 0.91727946616682676, -0.34103266577522645,
    0.024022800741513497, 0.011720808886749539, 0.005279368755842,
    -0.015503214612969836, -0.0046950538804386944, -0.0049324853729262232,
    0.025628347052127413, 0.0053815110155450525, 0.017788151497743245,
    -0.086861483233435025, 0.34103266577522739, 0.9236651764102688,
    0.085792049858502251, 0.0059643705927168722, 0.006347028564870804,
    -0.0097839256451718332, -0.0051333997379762594, -0.00386396642472545,
    0.1423623421498546, -0.082142491615516178, -0.013305452718520199,
    -0.093596755060135026, 0.024022800741517098, -0.085792049858503416,
    0.91827239587578757, -0.05392877352318063, -0.015504142872654428,
    0.058940366546277864, 0.013644079449034566, 0.016541650885136868,
    -0.020352363086397131, 0.0066139818778667391, -0.002304909609946709,
    0.0218064073273756, -0.011720808886747871, 0.0059643705927174351,
    0.0539287735231777, 0.99318026321431874, -0.022853276507520743,
    0.009543088136709392, 0.0090997881357000356, 0.0042889368298891853,
    0.017807623055968138, -0.010408716892377743, -0.000242287950229072,
    -0.013950796913079062, 0.0052793687558418166, -0.0063470285648705117,
    -0.01550414287264874, 0.022853276507519449, 0.98985276496064434,
    0.1201540048252005, 0.0021451654899012898, 0.00698115587727153,
    0.032936372652352018, -0.012030716924984083, 0.0026220392746821113,
    -0.031657653373419567, 0.015503214612970315, -0.0097839256451730978,
    -0.058940366546279405, 0.009543088136708686, -0.12015400482519938,
    0.97307822414522871, -0.027810733634519611, -0.0085855142768793621,
    -0.015411026685727624, 0.0076354824133262247, -8.7628800770794612E-5,
    0.012016758384294198, -0.0046950538804394195, 0.0051333997379755525,
    0.013644079449038338, -0.0090997881356991439, 0.0021451654898990394,
    0.027810733634516655, 0.98979434328317151, -0.094101624386088892,
    0.012666963982988319, -0.00484976047271726, 0.000651250579821529,
    -0.010989284062037292, 0.004932485372926846, -0.0038639664247229078,
    -0.016541650885141215, 0.0042889368298886059, -0.0069811558772717641,
    -0.0085855142768785, 0.094101624386088559, 0.98996640385047563 },

  /* Computed Parameter: DiscreteSS_C
   * Referenced by: '<S2>/Discrete SS'
   */
  { 62087.788382786093, -327875.12994459225, 1.6903815121940061E+7,
    -179378.18022524938, 5.0826481077793241E+6, -1.5402901711217016E+6,
    -244383.49429008458, 2.0828937886477932E+6, 222593.3995963186,
    206005.2040874958, -374086.070407629, -187075.21610736847,
    -153580.76446726918 },

  /* Computed Parameter: DiscreteSS_A_i
   * Referenced by: '<S4>/Discrete SS'
   */
  { 1.0, -0.14648335883684394, -0.3895203876204954, -0.12423211925889473,
    0.083076891295370991, -0.071818056556130355, 0.00829462694325408,
    0.01503655643164902, -0.006021306834948335, -0.0037369706336356778,
    0.0033445835825620055, 0.38952038762055086, 0.34796098222429717,
    -0.17642149326705234, 0.28216764992838733, -0.14907428418467264,
    0.026031532590773735, 0.031113192160817867, -0.014897439008234759,
    -0.0078786576803243046, 0.0082768473041591167, 0.12423211925887515,
    -0.17642149326706327, 0.88043499965190941, 0.41506143555964442,
    -0.021423916649198786, 0.00032965826493828993, 0.0034538677026222583,
    -0.00078047385068377218, -0.00084239654420054035, 0.00045346478536873185,
    0.083076891295344082, -0.28216764992840571, -0.41506143555964314,
    0.77909557541363972, 0.077703670607015329, -0.018688347035342306,
    -0.016864020877247067, 0.0094737045672939231, 0.0042856040865699527,
    -0.0052101436668315366, -0.071818056556108692, 0.14907428418468208,
    0.021423916649198634, 0.077703670607015884, 0.93599483742954215,
    0.10905365791878718, 0.015436624462816281, -0.021821186918471628,
    -0.0040291799978218511, 0.011340781791935633, -0.0082946269432433977,
    0.026031532590777558, 0.00032965826493884661, 0.018688347035342917,
    -0.10905365791878713, 0.9886051934165947, -0.021182634552532744,
    0.0037295720332154439, 0.0043722411193747382, -0.002062706432816534,
    0.015036556431647119, -0.03111319216080452, -0.0034538677026144265,
    -0.016864020877249065, 0.015436624462816736, 0.021182634552534944,
    0.99284207147420467, 0.057960916927762916, 0.0011570028449587946,
    -0.018661085232740276, 0.00602130683496308, -0.014897439008223972,
    -0.00078047385068282058, -0.0094737045673014986, 0.021821186918477106,
    0.0037295720332153949, -0.057960916927765838, 0.99568166253838875,
    -0.027368851028126539, 0.001109075613670946, -0.0037369706336476565,
    0.0078786576803509742, 0.000842396544217238, 0.0042856040865521137,
    -0.0040291799978144751, -0.004372241119370188, 0.0011570028449583753,
    0.027368851028125016, 0.9978382473186227, 0.052512070817354678,
    -0.0033445835825339767, 0.0082768473041750813, 0.00045346478536524673,
    0.0052101436668243444, -0.011340781791933987, -0.0020627064328170791,
    0.018661085232740113, 0.0011090756136695017, -0.052512070817353748,
    0.99771154250484428 },

  /* Computed Parameter: DiscreteSS_C_n
   * Referenced by: '<S4>/Discrete SS'
   */
  { -48166.723687419668, -1.5133302797078704E+7, -103544.91221783729,
    -149032.85823017173, 4.0659851297657248E+6, -1.6467400690320581E+6,
    210532.11523677409, 308444.00477421284, -123451.2196366787,
    -77621.53249335289, 69481.918108463287 },

  /* Computed Parameter: DiscreteSS_A_b
   * Referenced by: '<S6>/Discrete SS'
   */
  { 1.0, 0.69009342301672638, 0.34662349601266057, 0.12267821464909784,
    -0.054078011338367669, 0.0017083307511381208, 0.01043599353580498,
    -0.34662349601266157, -0.035690651183488242, 0.15178567916519192,
    -0.049769096750270053, 0.0027594516861234992, 0.010130354040532254,
    -0.12267821464909685, 0.15178567916519223, 0.91303177165987337,
    0.17834300839204922, -0.0025585271265612546, -0.00062337096770862259,
    -0.054078011338367551, 0.04976909675026913, -0.17834300839204872,
    0.94825749040349649, 0.00925360208045547, 0.084545152823803787,
    0.0017083307511425851, -0.0027594516861281322, 0.0025585271265614819,
    0.0092536020804948223, 0.97963343233556177, -0.2004706146468567,
    -0.010435993535805495, 0.010130354040528861, -0.0006233709677094532,
    -0.084545152823800138, 0.20047061464685895, 0.97470793933448363 },

  /* Computed Parameter: DiscreteSS_C_e
   * Referenced by: '<S6>/Discrete SS'
   */
  { 20234.828458972304, -63253.4778086883, 4.223292373217823E+6,
    -561615.20714360476, 158223.90732696466, -2399.8913694545627,
    -52020.3648431506 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */