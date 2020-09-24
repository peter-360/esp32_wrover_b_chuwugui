/*This is tone file*/

const char* tone_uri[] = {
   "flash://tone/0_a001_kaiji.mp3",
   "flash://tone/1_a002_wifi_con.mp3",
   "flash://tone/2_a002_wifi_discon.mp3",
   "flash://tone/3_a002_wifi_scpass.mp3",
   "flash://tone/4_a003_open.mp3",
   "flash://tone/5_a004_move_finger.mp3",
   "flash://tone/6_a005_suoding.mp3",
   "flash://tone/7_a006_jiesuo.mp3",
   "flash://tone/8_a007_firm_upok.mp3",
   "flash://tone/9_b001_gmset_fail.mp3",
   "flash://tone/10_b002_server_confail.mp3",
};

int get_tone_uri_num()
{
    return sizeof(tone_uri) / sizeof(char *) - 1;
}
