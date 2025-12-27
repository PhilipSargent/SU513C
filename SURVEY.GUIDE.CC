1 
0 
0 
0 
0 
0 
0     ***************************************************
      ***************************************************
      ***                                             ***
      ***  SU : A CAVE SURVEY DATA REDUCTION PROGRAM  ***
      ***                                             ***
      ***               RELEASE   5.13                ***
      ***                                             ***
      ***            USER REFERENCE GUIDE             ***
      ***                                             ***
      ***************************************************
      ***************************************************
0 
0 
0 
0                             by
0                      A.E.R.Waddington.
1 
          SU     USER REFERENCE GUIDE     VERSION 5.13
          ============================================
0           Contents
0       1.     Introduction and history of development
0       2.     Form of data
        2.1    Interactive input to control program
        2.2    Survey data input and keywords
        2.3    Plot control data
        2.4    Restrictions
        2.5    Output
0       3.0    Description of program operation - general
0       4.     Descriptions of program modules
        4.1    SURVEY & SUINIT interactive control program
        4.2    SU              data reduction
        4.3    CONVEC          vector conversion
        4.4    LIST,SCAN,SCAN1 station list control
        4.5    COORDS          coordinate calculaton & loops etc.
        4.6    SHEAD & CHEAD   output headings control
        4.7    DBOUT           database output
        4.8    PPLAN &  PELEV  plotting set-up
        4.9    DBREAD          database retrieval
        4.10   PLAN  &  ELEV   plotting control
        4.11   PLOT            package-dependent graphics
        4.12   ROSE            rose diagram routine
        4.13   ROSPLT          package dependent graphics
0       Appendix 1.      Program listings
0       Appendix 2.      Graphics interface to GHOST
0       Appendix 3.      Graphics interface to GDDM
1 
        1.   Introduction and history of development.
+       __   ________________________________________
0     Cave  surveys  cover  a wide range of sizes and timescales, from
 short linear caves which can be surveyed in one trip, to  large  area
 projects  with many caves explored and surveyed over a period of time
 in separate surveys, perhaps linked by a  surface survey, or  located
 merely  by  reference to a large scale map. The former type of survey
 is usually easily dealt  with  using  a  hand  calculator  -  perhaps
 programmable,  but  the  latter is far more tractable when a computer
 is available to process and store the survey data for later  use  and
 updating  with  new  data. The computer program SU has been developed
 over a number of years to fulfil the needs of this type  of  project,
 and  while  by  no  means a complete solution, it has now reached the
 stage where other users may find  it  useful  as  an  alternative  to
 developing  similar  programs  from scratch. This in turn requires an
 improved level of documentation, and maximised portability. This user
 reference is intended to enable other users to use the  program  with
 minimal   change,   but  also  provide  enough  information  for  the
 experienced  programmer  to  implement  SU  on  other  machines,  and
 customise  and/or  develop it to suit their own particular needs. The
 original program is,  however,  like  most  such  programs,  a moving
 target,  and  therefore  a  brief section is included to indicate the
 author's intentions regarding future developments.  Developments  not
 outlined  in  this  section  may,   however,  be  introduced,  if  an
 unforeseen need arises during the course of development. For example,
 the code to handle  underwater survey  data was written only two days
 after the need for it was discovered.
       The  program  started  life  in  1976,  but  has undergone such
 extensive change since its original inception that  it is doubtful if
 it  now contains a single line of pre-1979 code. It was found that as
 the  anticipated  survey  size  and  complexity  grew,   rather  more
 generalised and flexible methods of handling survey data were needed,
 such  that completely independent surveys could be linked without the
 need to renumber all of one set  of data.  It  is  thought  that  the
 technique  of  tagging  survey  stations first implemented in 1979 is
 adequate for this, and that the generalisation of  station  labelling
 to  unique  alphanumeric  strings  is  sufficient  to  cope with most
 existing or proposed survey projects. Many of the  improvements  have
 been   necessitated  in  order  to  deal  with  the  area  survey  of
 Schwarzmooskogel-South  by  Cambridge  University  Caving  Club,  and
 several important concepts have been inspired  by  the  U.S.  program
 Ellipse, used by the Association  for  Mexican  Cave Studies (1). The
 need  for  underwater  survey  handling  was in  response to the area
 survey of  Chapel-le-Dale being carried out by members  of  the  Cave
 Diving Group.
1     2.     Form of Data
+     __     ____________
0     In  general  terms,  a cave survey comprises a string of sets of
 three numbers -  a distance,  a  compass  bearing  and  a  clinometer
 reading. The basic function of a data reduction program is to convert
 these  numbers  to  (x,y,z)  vectors  and  then  add  them up to form
 cartesian coordinates  for  each  survey  station.  The  complexities
 arise from the need to calibrate instruments, which may vary from one
 part  of  a survey to another, perhaps done at a later date, from the
 fact that caves are seldom single passages,  but  possess  junctions,
 side passages, and loops, which require a survey to have a method for
 referring  back to previously surveyed points, and from the unhelpful
 habits of cavers taking backsights, or starting from the end of a new
 passage and working towards the known survey. Problems can also arise
 from using existing  survey data which may be in different units, and
 be  referred  to  different  origins or coordinate systems. Hence, in
 addition to the three basic numbers referred to above,  we  must also
 input  a  unique name or number for the survey station at each end of
 the survey leg, and a certain amount  of  supplementary  information,
 such  as  compass and clino corrections, coordinates of the origin(s)
 of the survey, and changes of measurement unit. Many new explorations
 in  the  UK  today  involve cave diving, where depths are measured by
 pressure gauge, and clino readings are not taken, so this alternative
 form of data input is also required. It  is also  helpful to the user
 to  annotate  the  survey with meaningful commentary,  though  as  of
 version 5.13, this annotation is  not  carried through to the printed
 output of the program.
0 
0     2.1     Interactive control information
+     ___     _______________________________
0     The program treats data reduction, plotting a plan, and plotting
 an  elevation as separate phases in the construction of a survey, not
 all of which may be required in a particular run of the program. Each
 option  is  activated by entering keyword commands at a terminal, and
 signals its progress and completion  by  messages  displayed  at  the
 terminal.
0     DATA command :
0     The  DATA  command  activates  the data reduction section of the
 program, which reads survey data from an  input  file,  and  converts
 this  to  vector  and  coordinate  form.  The  layout  of the data is
 specified in section 2.2, and  the  output  described  in  detail  in
 section  2.5.  All  survey  stations  are identified by six-character
 alphanumeric names, the only restriction being that these must differ
 from  any of the keywords used by the program. The program calculates
 coordinates of stations on the initial assumption that there is  only
 one route to a given point from the origin of the survey. If a survey
 leg  leads  to  a station whose coordinates are already defined, they
 are not redefined, but the program calculates the  misclosure  of the
 loop  thus  formed. The same applies to a survey station reached from
 different origins,  but  the  error  in  this  case  is  an  error of
 connection  between  two surveys rather than a misclosure. At version
 5, SU makes no attempt to close loops or  compensate  for  connection
 errors.
      After  the  coordinates have been calculated, SU places the data
 into a database file, which can later be  retrieved  for  plotting or
 for update with new data ( the latter option is not yet implemented.)
 The  form  of  the  database  file  is  independent  of  any internal
 restrictions on the number of survey stations with which a particular
 implementation of SU can handle.
1     PLAN command :
0     The  PLAN  command  activates  the  section of the program which
 plots a plan of the surveyed system, taking parameters to  define the
 scale orientation and spatial limits of the plan from a plot  control
 file,  in  a  format described in section 2.3. The coordinate data to
 plot the plan is that previously calculated by the DATA option, if it
 has been run, or is read from a database file previously created.
      In  addition  to  plotting, the program prints out the extent of
 the survey in scaled paper space,  ie. in real metres along the x and
 y axes of the plotter paper, at the  orientation selected to plot the
 plan. In cases where the survey extends  beyond  the  spatial  limits
 specified,  only  that  section  of  the  survey within the limits is
 plotted, and a warning is printed. In cases where the  spatial limits
 and  scale  specified  exceed  the  physical  area  available  on the
 plotter, no plotting is carried out and a warning message is issued.
0     ELEV command :
0     The  ELEV  command causes an elevation to be plotted, taking the
 same parameters as  for  the  PLAN  command,  and  printing analogous
 information  about the elevation. In the present implementation,  the
 horizontal axis  is  plotted  along the length of the paper on a drum
 plotter, but it is recognised  that  for  vertical  systems, this may
 prove  restrictive on scale and it is intended to provide  an  option
 to plot with the vertical axis along the paper.
0     ROSE command :
0     The  ROSE  command instructs the program to plot rose diagram(s)
 from the cave survey data. It reads the survey data  from  the  input
 file  and  takes additional parameters from the terminal to determine
 the interval size ( in degrees ) for the sectors of the rose diagram.
 This option is currently only implemented for the VM/4341  version of
 the  program,  and interfaces directly to an IBM 3279 colour graphics
 terminal. A version  to  drive  GHOST  graphical software is expected
 soon. The ROSE section of the program executes  independently  of the
 other sections, and does not need the DATA section to have  been  run
 at any time, since it works with the original data input file.
0     EXIT command :
0     When all required sections of the program have  been  completed,
 the keyword EXIT will terminate the program and close files.
0     2.2     Survey data input and keywords.
+     ___     _______________________________
0     Survey data is input in a fixed format, some fields of which are
 also  used  for  the  input of control information - ie. keywords and
 associated data. This  ensures that the program never reads a line in
 an incorrect format, by  placing any data which will not fit into the
 standard layout on a line  following  the  appropriate keyword, which
+                           _________
 does  fit in. The only exceptions to this are the first line of input
 which contains a title for the survey in the first 48 columns, and no
 other information, and the second line which contains the coordinates
 of the initial origin.
1     The  standard  format for data lines comprises two six-character
 alphameric fields, followed  by  four  six-digit real-numeric fields,
 which have specified positions for implicit  decimal points according
 to the FORTRAN format specifiers F6.2, F6.1, F6.1, F6.2,  ( but it is
 recommended  that  the  decimal  point  be included explicitly )  and
 finally, a thirty six-character alphameric field for commentary which
 is not currently read by the program. The input formats of the  first
 two  lines,  and the interpretations of the standard input format for
 each keyword are as follows. In all cases lower case x indicates that
 a field is unused.
0Title line:
0|...+....1....+....2....+....3....+....4....+....5....+....6
 TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
0where T represents alphameric title data.
0Origin coordinates:
0|...+....1....+....2....+....3....+....4....+....5....+....6
 OOOOOOxxxxxxEEEEEEEE.EEENNNNNNNN.NNNHHHHHHHH.HHH
0where O represents alphameric data - the name of the origin,
       E represents numeric data    - the  east  coordinate in metres
       n represents numeric data    - the north  coordinate in metres
       h represents numeric data    - the height coordinate in metres
0Calibration of instruments.
0|...+....1....+....2....+....3....+....4....+....5....+....6
 CHANGExxxxxxxxxxxxDDDD.DCCCC.Cxxxxxx      comments
0where CHANGE is the keyword to change the instrument calibration.
       D represents numeric data    - the declination to be subtracted
                                      from input compass bearings.
       C represents numeric data    - the correction to be  subtracted
                                      from input clino readings.
0Change of current units.
0|...+....1....+....2....+....3....+....4....+....5....+....6
 INFEETxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx      comments
0|...+....1....+....2....+....3....+....4....+....5....+....6
 METRICxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx      comments
0where INFEET changes the current units to feet and decimal fractions
               of feet. It is not proposed to support inches.
       METRIC returns the current units to metres.
0Change of input data format
0|...+....1....+....2....+....3....+....4....+....5....+....6
 DIVINGSSSSSSxxxxxxxxxxxxxxxxxxxxxxxx      comments
0|...+....1....+....2....+....3....+....4....+....5....+....6
 NORMALxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx      comments
0where DIVING indicates a change to underwater style survey data with
       SSSSSS as the survey station at zero depth. This survey station
              should already exist within the survey.
       NORMAL indicates a return to normal length/compass/clino format
1Normal input data
0|...+....1....+....2....+....3....+....4....+....5....+....6
 FFFFFFTTTTTTLLL.LLBBBB.BCCCC.CVVV.VV      comments
0where F represents alphameric data - the name of the station FROM
       T represents alphameric data - the name of the station  TO
       L represents numeric data    - the measured length in current
                                      units ( default is metres )
       B represents numeric data    - the bearing in standard degrees
       C represents numeric data    - the clinometer reading in std.
                                      degrees ( +ve up, -ve down )
       V represents numeric data    - a plumbed vertical component of
          the  survey  leg. This eliminates  problems with clinometers
          having non-zero calibrations, when +90 readings get changed.
+                                            _
0Diving input data
0|...+....1....+....2....+....3....+....4....+....5....+....6
 FFFFFFTTTTTTLLL.LLBBBB.Bdddd.dDDDD.D      comments
0where F represents alphameric data - the name of the station FROM
       T represents alphameric data - the name of the station  TO
       L represents numeric data - the  length of the survey leg
       B represents numeric data - the bearing of the survey leg
       d represents numeric data - the depth of the FROM station
       D represents numeric data - the depth of the  TO  station
       Only one depth is required, viz that of the currently undefined
       station ( usually the TO station ). If the FROM depth is stated
       it should not have an assumed point. If both depths are quoted,
       and the depth of a previously  defined  station is altered, the
       difference in  depths will be used to calculate a new depth for
       the undefined station.  This facilitates the continuation of an
       underwater  survey  from  an  existing  survey station if water
       levels have changed since the  previous survey. It is necessary
       in this case to ensure that both  depths  are  quoted  for  the
       final leg of a closed loop.
0New origin
0|...+....1....+....2....+....3....+....4....+....5....+....6
 ORIGINxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx      comments
 OOOOOOxxxxxxEEEEEEEE.EEENNNNNNNN.NNNHHHHHHHH.HHH
0where ORIGIN is the keyword introducing an additional origin
       O represents alphameric data - the name of the new origin
       E represents numeric data    - the  east  coordinate
       N represents numeric data    - the north  coordinate
       H represents numeric data    - the height coordinate
0End-of-survey marker
0|...+....1....+....2....+....3....+....4....+....5....+....6
 END   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx      comments
0where END    is the  keyword  to terminate the input for this survey,
               the three blanks following the keyword must be present.
  
1     2.3     Plot Control Data
+     ___     _________________
0     The plot control input stream comprises a single input record
 specifying the scale of the plot ( assuming default paper size ),
 and the limits on range of paper-space coordinates to be plotted.
0Format:
0|...+....1....+....2....+....3....+....4....+....5....+....6
 SSSSS.OOOOO.PXMINXX.PXMAXXX.PYMINYY.PYMAXYY.PZMINZZ.PZMAXZZ.
0where SSSSS. is the scale for plotting.
       OOOOO. is the orientation. ie. the bearing along which the
                            plotter paper long axis should be aligned.
     PXMINXX. is the minimum value of the paper long  axis coordinate.
     PXMAXXX. is the maximum value of the paper long  axis coordinate.
     PYMINYY. is the minimum value of the paper width axis coordinate.
     PYMAXYY. is the maximum value of the paper width axis coordinate.
     PZMINZZ. is the minimum value of the height coordinate.
     PZMAXZZ. is the maximum value of the height coordinate.
                all the above are in metres of survey space; ie. to be
                divided  by  SCALE  to  get  the  actual  paper  size.
0     It  is  intended to upgrade this interface at some stage so that
 elevations may  optionally  be  plotted  with the vertical axis along
 the length of the paper as an alternative  to  the  present situation
 where the vertical axis is always across the width of the paper.
  
0     2.4     Restrictions
+     ___     ____________
0     There  are  several restrictions on the input data to SU, few of
 which pose any problem  to normal surveys. The total number of survey
 stations may not exceed 1000,  nor  may  the  number  of survey legs,
 though  this  particular  restriction  is  easily  dealt  with :- see
 Section  3  :  'Description  of  program operation', and section 4.1.
 Survey stations can have names of up to  six  characters,  which must
 not be the same as any of the keywords available. It is also sensible
 to  restrict  the  characters  to  those  which can be printed on the
 installation in use, since it is useful for  the  user  to be able to
 tell the stations apart ! To maximise portability of survey  data, it
 is  recommended  that station names be restricted to the 64 character
 ASCII set.
      While  the  program  will  quite  happily  detect  and correctly
 process backsights, it is not capable of backtracking when  a section
 of  the system is 'surveyed out', ie. the survey starts at an unknown
 point and proceeds towards an eventual connection with a known survey
 station.  In  this  case,  the  conversion  to  vector  form  will be
 unaffected, but in the coordinate  section  of  the  printout,  these
 stations  will  be  flagged  as 'UNDEFINED'. Input order is therefore
 restricted so that in any survey  leg,  at  least  one  of the survey
 stations will have been previously defined. If survey data is already
 available in machine readable form, and cannot be reordered suitably,
 then the facility to define additional independent origins  could  be
 used,  leading  to  the definition  of a connection error which could
 then be subtracted from the initially  used  origin  coordinates  for
 subsequent runs. It will normally be possible, however, to resequence
 survey data to overcome this restriction.
1     2.5     Output
+     ___     ______
0     The  output from the DATA section of the program is divided into
 two sections.  The  first  is a reflection of the input data, both in
 tape/compass/clino  form ( with  readings  uncorrected  for  magnetic
 declination  and  clino  error ),  and  in plan-length, and cartesian
 vector form ( after such correction ). This  section  of  the  output
 also  reflects  the  initial  calibration  corrections to compass and
 clino, and any subsequent changes.
      The  second  section  of  the  output  reflects  the coordinates
 supplied  for  the  origin,  followed by, for each survey  leg  ; the
 vector form of the leg, and the  coordinates  of whichever of the two
 stations was not previously defined. If neither  station was defined,
 then  the  word 'UNDEFINED' appears in place of the coordinate  data,
 while if both stations were already  defined, a misclosure  or survey
 connection error is printed.
     A  final  section  of  the  output  prints statistics such as the
 total  traverse  length  of  the  survey,   and   the   corresponding
 horizontal plan length.
      Output  from the PLAN and ELEV sections of the program comprises
 the plots themselves,  and  statistics about the plot, output to both
 printer and terminal. These consist  of  a  reflection of the spatial
 limits selected for the plot, and the actual  extent  of  the survey,
 followed by warning messages if the survey extends further  than  the
 limits  selected ( in this case, a plot of the area within the limits
 is produced ), or  if  the  limits selected would exceed the hardware
 capabilities of the plotter ( in this case, no plot is produced. ).
     The  output  from ROSE, in addition to the diagram itself, is the
 data for the rose diagram in  tabular  form, both in absolute metres,
 and as a fraction of the total length of the survey.
1     3.     Description of program operation - general outline.
      ==     ===================================================
0     The  various  sections  of  the  program  are called from a main
 routine which communicates with the user, and enables  options  to be
 selected from an internal menu. This main routine also allocates  the
 storage  which  is  used by the subroutines for storing data, so that
 an increase in the number  of  survey stations to be handled requires
 only a change to SURVEY and its associated block data segment SUINIT.
      The DATA section of the program is by far the largest part, this
 is  SU  and  carries  out  all  the list handling and setting up of a
 database for the other routines  to  use. The data input initially is
 not  stored  as  such,  but is corrected for instrument  calibration,
 converted to cartesian vector  form, and  stored  in  this  way.  The
 'from'  and  'to'  fields  are  stored  as  numbers referring into an
 internal  list  of  survey stations created by  a  routine  LIST  and
 indexed via a routine SCAN.
      Once the data  are stored in vector form, a large routine COORDS
 is called  to  construct the coordinates for each survey station. The
 routine proceeds  through  the list of survey legs, determining which
 of  the  survey  stations  are   defined  and  which  undefined,  and
 calculating the coordinates of the  undefined  station.  Each station
 now  has  associated  with  it  a  six  character  name, an ( x,y,z )
 coordinate, and a number OINDEX which  specifies  from  which  origin
 the  survey  reached  this  station.  Initially  this  is zero for an
 undefined station, and on definition, is set equal to OINDEX  for the
 station at the other end of the defining survey leg. In the case of a
 leg  for which both stations are defined, this enables the program to
 determine  whether  the  cause  is  a loop closure or an inter-survey
 connection.
      The routines to plot plan and elevation are closely related, and
 work  by   converting  the   real-space  coordinates  to  paper-space
 coordinates according to the  orientation  of  the  survey,  and then
 working through the survey legs,  plotting line segments between  the
 coordinates  of  the  'from' and 'to' stations. Scaling to paper size
 is carried out in  the  package-dependent  subroutine  PLOT,  and  is
 usually done by the graphics software itself.
1        4.   Description of Program Modules.
         ==   ===============================
0     The descriptions of the internal workings of each section of the
 program  are  in  the  same order as the descriptions of the options,
 and start with the highest  level  subroutines, working down into the
 calling  structure  in  each case. Listings  of  the  implementation-
 independent parts of version 5.2  are included in Appendix 1, and the
 implementation  dependent   routines  for  plotting  are  covered  in
 Appendix 2 ( GHOST ) and Appendix 3 ( IBM GDDM ).
0     4.1   SURVEY interactive control program and BLOCK DATA SUINIT
+     ___   ________________________________________________________
0     The  main  routine  acts  only  as static storage allocation and
 interactive control program, all data handling  and calculation being
 dealt  with  in the subroutines called in by the various options. The
 storage allocation  is  controlled  by the parameter ISZ, which needs
 only  to  be  reset  in  this  routine  and its associated BLOCK DATA
 SUINIT, in order to increase the number of  survey  stations that the
 program can handle. Additional options can be added to  the system by
 changing  the  parameter   NOPTS  and  the  DATA  OPTS  statement  to
 accomodate  additional options, and by extending the ELSE IF chain to
 cover the calling  of  new  routines.  All  the existing routines can
 then  be linked without change, and will perform  unaffected  by  any
 other options in the system.
      The program  consists  of a hard loop prompting the user for the
 name of an option to be performed,  reading a response, and filtering
 it through an  IF THEN,  ELSE IF  ...  command filter. The program is
 terminated if the option EXIT is entered, and the loop is closed with
 a warning message if an unknown option was selected. The loop is also
 closed  with  an  'option  completed'  message  after the appropriate
 routine has terminated.
      The BLOCK DATA segment, SUINIT, contains all the set up data for
 COMMON storage. These comprise the input/output channel numbers, ( in
 case these need to be  changed  to conform with system standards when
 implemented elsewhere. ) the number  of lines of output per page, the
 global flags which have default values,  the SU version number, and a
 few other variables which are stored in COMMON  which require initial
 values.
      In  order  to  change the number of survey legs that the program
 can handle, it is necessary  to  change the PARAMETER ISZ in the main
 routine and its block data segment.  Since  data  is  dumped  to  the
 database  file  in  multiples  of 24 data items, it is a good idea to
 ensure that ISZ is always a multiple  of  24. It is only necessary to
 recompile these two segments and link edit  again  in order to effect
 the  change,  since  the dimensioning of all data in the  subprograms
 is controlled by the COMMON  variable  SIZE,  which is initialised by
 ISZ.
0     4.2   SU                    Data reduction routine.
+     ___   __                    _______________________
0     SU  is  the main core of the survey program, processing the main
 input file and  generating  the  vector equivalent through CONVEC and
 a coordinate set through COORDS. The  resulting  dataset is output to
 a  database  file, where it can be used for running the PLAN and ELEV
 options without the need for recalculation by SU.
      The  first  section  of SU checks whether the coordinate data is
 already in memory, and if  so,  warns  the user that recalculation is
 unnecessary. The data in memory could of  course  be from an existing
 database file, which the user requires to be updated,  so  the option
 exists  to  redefine  it from the main input file. In this case, some
 variables which are initially set up in DATA need to be reinitialised
 before SU can run.
1     The  title  and  initial  origin  coordinates form the first two
 lines of input data and are mandatory, so  are  read outside the main
 read loop. The main read loop expects data in the standard keyword or
 survey  data  format,  and  checks  for  all possible keywords before
 assuming  that an input line is survey data.  Whenever  a  recognised
 keyword is read  in,  the  program will jump back to the initial READ
 statement without getting to  the  end  of  the DO loop, so only when
 survey data is processed will I be incremented.  Thus,  when  END  is
 encountered  and  the  loop  exitted,  I  will be a true count of the
 number of survey legs processed and not of  the  number of data lines
 read.
      The  action  required  for  each  keyword  is  performed in line
 immediately after the if statement which recognises it.  For  CHANGE,
 this  involves treating some of the numeric input data as update data
 for the  calibration  values  DEC and CLINO. The output line count is
 updated, and headings output if  necessary  via SHEAD, before the new
 calibration is reflected. For keywords FEET and  METRIC,  all that is
 needed is the change of state of a flag, while for DIVING and NORMAL,
 a  flag  change  is  also  necessary, but in addition, for DIVING, an
 array of scratch storage, referenced  as DEPTH within SU, needs to be
 set up to keep track of the depth of underwater  surveys.  A call  to
 SCAN1  is  needed  to find the index of the surface survey station in
 the station list STA,  and the program cannot continue if the station
 is not already known.
      In the case of a new origin definition, a second input line must
 be  read,  and  the  new  station name added to the list. The routine
 needs to ensure that the station  name  given  is  not already on the
 station list before accepting the input, via a call  to  SCAN1 before
 LISTLN is incremented. The total number of origins known,  OCOUNT  is
 incremented, and the OINDEX of the new origin is set to this value.
      If no keyword is matched by the first input field, then the line
 is  assumed  to  be  survey  data  input, and is handed to CONVEC for
 conversion to vector form. The routine continues  to  end the DO loop
 and hence increments I before the next line is read in.
     When  END is encountered, the program skips out of the read loop,
 and rewinds  the  input dataset in case it is later required by ROSE.
 Because I was incremented  before  the END line was read, it needs to
 be decremented by one to reflect the true number of survey legs read.
 With all the survey data now in vector  form, all that remains for SU
 is to call COORDS to convert the data to a  coordinate  dataset,  and
 output  the  dataset to a database file. The size of this file is set
 to the smallest  possible subject to the requirement that it contains
 a multiple of 24 data  items ( see section 4.7 : DBOUT ), and this is
 achieved by the definition of DBSIZE under integer arithmetic.
0     4.3   CONVEC                Vector conversion routine.
+     ___   ______                __________________________
0     The  routine  CONVEC  receives a line of survey data and returns
 the vector equivalent, having  inserted any previously unknown survey
 station  onto  the  station list STA,  and  indexed  it  through  the
 relevant pointer IF or  IT. This is achieved by a call to LIST, which
 searches  the  station list  and  adds  any  new  station(s)  to  it,
 returning the number of new stations ( 0, 1 or 2 ) in NFLAG. If NFLAG
 is zero, then a closure  is  indicated,  while if it is two, then the
 leg will be isolated from the rest of the survey.
      The course of the conversion is now controlled by various flags.
 If  INFEET  is  true,  then all length figures must be converted into
 metric measurements before  use.  LEG and VERT are always interpreted
 as lengths, but ELEV also has dimensions  of length if the data is to
 be interpreted as an underwater survey leg,  when  ELEV  and VERT are
 depths below water level.
1     If  underwater  survey  is  being  processed,  then the vertical
 component of  the  vector is determined by the difference  in  depths
 of  the two stations ( noting that  height and depth  are positive in
 opposite  directions ), which  may not  both  be quoted.  The program
 assumes that  the  most recently  defined station will have its depth
 quoted ( or possibly both stations ),  and  sets  the  DEPTH for this
 station.  If one or both of the depths is not quoted ( ie. is zero ),
 then the vertical  component  of  the  vector  is  obtained  from the
 DEPTH  array,  while if  both are quoted, then the quoted figures are
 used, which caters for a survey  which  is  partly  finished and then
 resumed  when  water levels have changed. The possibility exists here
 for a failure in the  unlikely  event  of a loop closure to a station
 which has zero depth on this survey, but  had  a  non-zero depth when
 surveyed  at the start of the loop survey (!). This  is  a  difficult
 situation to  get  round,  since  FORTRAN  treats  blank input  to  a
 numeric  field  as a  zero input, and  the program cannot distinguish
 the two. Once the vertical component of  the  vector  is  known,  the
 horizontal component is obtained via Pythagoras'.
      For  conventional  compass/clino  surveys, the vertical and plan
 length  components  of the  vector  are obtained  by  correcting  the
 clino reading  for calibration  error and  taking sine and cosine. In
 addition to this, the vertical component of the vector is incremented
 by  any  interval obtained  by  plumbing. This  overcomes any problem
 which  may arise  through the corruption of  90 clinometer readings
 when a clinometer calibration correction is applied.
      For both types of survey, the Easting and Northing components of
 the  vector  are  obtained  from  the plan-length using the corrected
 compass reading, and the total plan length incremented.
      The output formats differ for  the two forms of survey data, but
 in  both  cases,  the  remaining page space is checked and a new page
 with headings started if necessary via a call to SHEAD.
0     4.4   LIST, SCAN & SCAN1    Survey station list routines.
+     ___   __________________    _____________________________
0     LIST calls SCAN to  ascertain if the survey stations being input
 are  already  on  the list of known survey stations STA, and gets the
 indices in the list  IF and IT  if  they  do.  If  IF  and/or  IT are
 returned  negative, the  survey stations are new and need to be added
 to the end of the list, and  the  list  size,  LISTLN, increased. The
 indices  IF  and  IT  are  set  to  point  to the position of the new
 stations in the station list.
0     SCAN  searches  the list of survey stations known so far, trying
 to match the names of  the  two  survey stations in the current call.
 The search starts from the end of  the  list  and  works  toward  the
 beginning,  since  a  survey  leg is most likely to refer to a survey
 station defined by the previous  leg.  If  both  survey  stations are
 found the search stops immediately.  This only saves time  when  both
 survey  stations  are  known,  however, since the entire list must be
 scanned to prove that a new station  is not on the list. If a station
 is not on the list, the appropriate pointer is returned negative.
0     SCAN1  is a faster search routine for a single station, which is
 normally expected  to be a known station. Again, it is most likely to
 have been defined recently,  and a search from the end of the list is
 most likely to find it quickly.  The  search  is stopped as soon as a
 match is found.
1     4.5   COORDS                coordinate calculation routine.
+     ___   ______                _______________________________
0     The  general  function  of  COORDS  is to go through the list of
 survey legs, and determine if each one is a foresight or a backsight,
 and thus calculate the unknown survey station  coordinates  from  the
 known station and the survey vector. It must also cope with the cases
 where  neither survey station is yet defined, and the case where both
 survey stations are known, and a misclosure needs to be calculated.
      COORDS  keeps  track  of which  survey stations are known via an
 array called OINDEX, which contains the  index  of  the  origin  from
 which  the  survey  station was defined, and is zero for an undefined
 station. The scalar  OCURR  records  which  origin  was most recently
 printed out.
      The  routine  contains  a  brief initialisation, and then a loop
 running  through the survey legs. The  first  step  is  to  determine
 which station(s)  are  defined,  ie.  have a non-zero OINDEX. If both
 stations are undefined, the data is of  little  value, but is printed
 out  so  that  it  may  be  identified by the user, and  the  routine
 continues to further legs, which  may  contain  useful  data.  Before
 each  line  is  printed,  the  routine CHEAD is called to ensure that
 there is space on the current page, and to output headings if not.
      In the event that one station  is defined and the other not, the
 appropriate value of A is set as a sign  multiplier :-  positive  for
 a  foresight,  and  negative  for a backsight. New pointers ID to the
 defined  station and IU to the undefined  station  are  assigned  the
 appropriate  values  from IF and IT. The coordinates of the undefined
 station  are then  calculated  from  those  of  the  defined  station
 incremented  by  the  signed  value of  the survey vector. The OINDEX
 value of the new station is set to that of  the  old to indicate that
 this  station  has  been  defined  with  respect to the  same  origin
 coordinates  as the previously  defined station.  If  this  value  of
 OINDEX  is greater than  the value  of  OCURR ( this is  true for the
 first survey leg processed, and subsequently for any survey leg which
 starts  from or ends  at an origin  which has not yet been printed ),
 then the coordinates of the relevant  origin  are  printed before the
 survey leg data and the coordinates of the station at  the  other end
 of  the  survey  leg.  In  this case, CHEAD is called with parameters
 J ( which keeps track of the  number of  lines output so far ) and 2,
 the latter indicating that two contiguous  lines are required for the
 printing of the origin and survey leg following.
      In  the  event  that both of the survey stations involved in the
 current leg are already  defined,  neither  will be redefined by this
 leg, but a misclosure is calculated. If the  two survey stations have
 been defined by reference to the same origin,  a  single line will be
 printed stating the misclosure, but if the OINDEX values differ, then
 the  situation is more complex. A line is printed stating  which  two
 origins  gave  rise  to the surveys now connecting, which may in turn
 be preceded by the coordinate  information for the more recent origin
 if this has not previously been  printed.  The misclosure information
 is  then  printed.  CHEAD  is  called  to  request  one, two or three
 contiguous lines as required.
      The  final  line  of  code sets the global flag DBCORE to inform
 other program modules that the  coordinate  data  for  this survey is
 in memory and does not need to be retrieved from external storage.
1     4.6   SHEAD & CHEAD         output headings control routines.
+     ___   _____________         _________________________________
0     SHEAD and CHEAD have the function of printing page headings when
 there  is no room on the current page for the output of the following
 lines. They each receive a parameter J which the calling routine uses
 to recors the number of lines output so far.
      SHEAD  prints  the  headings  required  by  SU for the output of
 calibration corrections caused by CHANGE keyword  input  and  of  the
 original  survey  data,  and  the  vector  equivalent ( calculated by
 CONVEC ). The COMMON variable LINES contains  the  number of lines of
 data ( excluding the headings ) required per page, and the routine is
 very  simple  since  CONVEC  only  requires to print a single line of
 output at a time. The line counter is incremented, and if end-of-page
 is reached, a new set of headings are printed on a fresh page.
      CHEAD  prints  the headings required by COORDS for the output of
 station and origin coordinate  data,  and  misclosure information. It
 receives  an  additional parameter I which specifies  the  number  of
 contiguous lines  that  COORDS  wishes  to  print,  and  if there are
 insufficient  lines  on the  current  page, outputs a  new page  with
 headings.  A short  loop  determines on which of the lines needed the
 page would run out, if at all.  If  the  page  can  hold the required
 number of contiguous lines, the loop falls through,  no  headings are
 printed, and the line count, J is incremented by the number  of lines
 to be  output. If the page cannot hold the required output, the  loop
 exits with  K representing  the number of blank lines still remaining
 on the page. A new page with  headings  is printed, and the linecount
 is incremented by the sum of the number of  lines  to  be output, and
 the number of blank lines left unused on the previous page.
0     4.7   DBOUT                 database output routine.
+     ___   _____                 ________________________
0     DBOUT  writes  the  survey  station  list  STA,  the  survey leg
 endpoint pointers IF and IT, and the coordinate data EAST, NORTH  and
 HEIGHT,  to  a  database  file  in a standard format, together with a
 small amount of information needed to interpret the data.
      Since  the data in STA, IF and IT are written at a density of 12
 items per line,  and  the coordinates at 8 per line, the data need to
 comprise a multiple of  24 items. The COMMON variable DBSIZE contains
 the smallest multiple of  24  greater  than or equal to the number of
 survey stations, and this is used to dimension the arrays. This means
 that the write statements do not need to  contain implied DO loops in
 order to write arrays whose size is not known  at compile time, which
 in turn, gives more efficient I/O. The additional information written
 to disc includes the title of the survey, the size  of  the database,
 the number of survey legs and the number of survey stations.  This is
 sufficient  information  for  the  reconstruction  of  the survey for
 plotting purposes.
0     4.8   PPLAN & PELEV         plotting setup routines.
+     ___   _____________         ________________________
0     PPLAN  and  PELEV  are  very  similar  routines which set up the
 parameters for PLAN & ELEV respectively, in order  to  plot  plan and
 elevation  views  of the survey. The routines read scale, window size
 and orientation information  from  the PCIN ( plotting control ) disc
 file, and if necessary, call DBREAD to  obtain  the  coordinate  data
 needed  to  plot  the  survey.  They then hand this information on to
 PLAN & ELEV to calculate the paper-space coordinates.
0     4.9   DBREAD                database retrieval routine.
+     ___   ______                ___________________________
0     DBREAD  is  a routine to read survey connectivity and coordinate
 data from a disc  file,  to  enable  plotting  of  plan  or elevation
 without the need for calculation from raw data.
1     The first line of information in the file is read by the calling
 routine, which then passes the database size DBSIZE to DBREAD through
 COMMON,  and  DBREAD  uses  this to dimension the arrays STA, IF, IT,
 EAST, NORTH and HEIGHT. These  can  then  be read in without the need
 for any implied DO loops in the read statements,  which  improves the
 efficiency - needing only one call to the I/O routines per array.
      The  final  act  of  DBREAD  is to set the global flag DBCORE to
 indicate to other routines that the  survey  coordinate  data  is  in
 memory, and does not need to be read or calculated again.
0     4.10  PLAN & ELEV           plotting control routines.
+     ____  ___________           __________________________
0     PLAN  and ELEV are structurally identical routines which perform
 the calculation  of  paper-space coordinates for the plotting of plan
 and elevation views of  the  survey.  They each receive parameters to
 control the scale of the plot, the orientation  of  the view, and the
 range  of  x, y and z coordinates to include. They also  receive  the
 survey description  in  terms  of IF & IT and the coordinate data. In
 addition, array(s) are passed for  the  storage of paper-space coord-
 inates within the routines.
      For the plan view, the parameter ANGLE controls the direction of
 the paper  long axis, while for the elevation, this is the bearing of
 a left-to-right  line  in the vertical plane. Thus the elevation is a
 side view along the maximum  length  of the plan. For both views, the
 paper space coordinate in this direction  is  PX,  which need only be
 calculated once, by whichever routine runs first. The  flag  PXDEF is
 used  to  indicate  that  PX has been defined and does not need to be
 recalculated. Similarly, the  range of PX is found as PXMIN to PXMAX,
 and these values are kept in the same COMMON block as PXDEF.
      PLAN  needs  to  calculate a transformed coordinate PY, along an
 axis perpendicular to PX,  and  find  the  range  of  these values as
 PYMIN to PYMAX. ELEV does not need to transform coordinates  in  this
 direction,  since  the  second coordinate is always HEIGHT, but again
 the range is found as PZMIN to PZMAX.
      Once  the  ranges  of the coordinate values are known, these are
 compared with the window  area  as  defined  by WRANGE, and a warning
 printed if the survey extends beyond the window  area.  The survey is
 still  plotted in these cases, however, since it is often  useful  to
 window a detail view of a large survey.
      The  actual  plotting  is carried out by the routine PLOT, which
 receives the scale, the relevant  sections  of  the WRANGE, the paper
 x and y coordinates ( PX, PY ) or ( PX, HEIGHT ) and the connectivity
 data IF and IT. This routine contains all the package dependent code.
0     4.11  PLOT                  package-dependent graphics.
+     ____  ____                  ___________________________
0     Only  the  interface and general outline of PLOT are given here,
 for  the  detailed  coding  of  any  particular  implementation,  see
 Appendices 2 & 3.
      PLOT receives  a  scalar  real parameter SCALE which defines the
 actual scale  of the final plot, and two real parameter pairs PXR and
 PYR  which  contain the maximum and minimum values of the paper x & y
 coordinates. PLOT is assumed  to  know the size of paper that it will
 use, and should check that the plot being requested will actually fit
 onto the hardware available. Current implementations will abort if an
 attempt is made to plot a survey larger than the hardware paper area,
 since  the  window  size  parameters to PLAN and ELEV are designed to
 allow the user to trim surveys to the required size.
      The remaining coordinates  are PX and PY, the paper space coord-
 inates, and IF and IT, which determine between which coordinates line
 segments are to be drawn to  define the survey. These are all arrays,
 and  are  dimensioned  by  values in the /SIZES/ COMMON block, LISTLN
 for the coordinates, and NO for the indices.
1     4.12  ROSE                  rose diagram routine.
+     ____  ____                  _____________________
0     ROSE  works  from the raw input data, not all of which is needed
 to calculate polar  frequency,  so  much  of the code is a simplified
 version of the read loop in SU.
      The  first section of the routine interrogates the user terminal
 for the angular  size  of  segments in the rose diagram. This is then
 adjusted so that it is an exact  sub-multiple of 180 degrees, subject
 to the constraint that no more than  45  segments will be allowed. If
 a smaller value of interval than 4 degrees  is  requested, this value
 will  be  rounded  up  to  45  intervals  of  4 degrees.  The user is
 informed of the values in use. The read loop follows  the  same  form
 as in SU, but any data that is not required is read with a simplified
 read statement - this includes items such as origin coordinates. Data
 for  compass  and  clino recalibration, and keyword input for unit or
 input format change is  respected. The compass bearing is only needed
 in degrees for distribution into  intervals, but the clino reading is
 still required in radians for the calculation  of  plan length. IBEAR
 is the sequential number of the interval containing the survey vector
 in the range 1 to NINTS, and the appropriate cumulative segment total
 BELEN(IBEAR)  is  incremented with the plan length of  the  leg.  The
 rewind statement is  required  to restore the state of the input file
 in case ROSE has been called before  the  DATA  command  is issued. A
 short loop prints out the data used to construct the rose  diagram in
 the  form  of  a  frequency  table  before  the data is handed to the
 graphics dependent routine ROSPLT.
0     4.13  ROSPLT                package-dependent graphics.
+     ____  ______                ___________________________
0     The  interface  to  ROSPLT  and an outline of its functioning is
 described here but not the coding detail of any particular implement-
 ation, which is covered in appendices 2 & 3.
      ROSPLT is called with four parameters, which constitutes a small
 degree  of  redundancy to allow for alternative implementations which
 may wish to apply  the  data slightly differently. The parameters are
 the real scalar INTSZ, specifying  the  interval size in degrees; the
 integer scalar NINTS specifying the number  of  intervals ; the  real
 array RANGE which contains the interval boundary values, and the real
 array BEFRCT which specifies the fraction of the data in each falling
 within each interval.
      It  is  envisaged that ROSPLT will access the case title through
 COMMON, and will  not  need  access  to  any other data from the main
 routines. Scaling will be set up in graphics  space so that a uniform
 distribution  of  data  in  the intervals would generate  a  circular
 diagram of radius independent of the interval size. Segments would be
 drawn in opposing pairs to maintain  symmetry  and  the  absence of a
 'preferred'  direction.  Any  graphics package which supported  polar
 coordinates would make implementation  very simple, but most packages
 will  contain the bare minimum software  to  draw  arcs  of  circles.
 Shading  of the segments when drawn makes the diagram easier to read,
 and the version  implemented  first was for a colour terminal and dot
 matrix printer rather than a drum  plotter.  Options  for the user to
 specify  shading  colour,  or  additional  titling data could best be
 handled by ROSPLT accessing /PARMS/ and interrogating  the  user  via
 the TTYIN and TTYOUT units.
1                APPENDIX  1      PROGRAM LISTINGS
                 ===========      ================
0 
0       INTERACTIVE CONTROLLING ROUTINE : SURVEY
+       ________________________________________
0       *....*...1.........2.........3.........4.........5.........6.........7.*.......8
0   1         PROGRAM SU513C
        C
        C     SU     VERSION 5.13C
        C
    2         PARAMETER  (  ISZ=1008, ISZM1=(ISZ-1) , ISZ7=(7*ISZ) , NOPTS=5 )
    3         EXTERNAL SUINIT
    4         REAL    E(ISZ),    N(ISZ),     H(ISZ),      DIST(ISZ),
             &        EAST(ISZ), NORTH(ISZ), HEIGHT(ISZ), SCRTCH(ISZ),
             &        PX(ISZ),   PY(ISZ),    LENGTH
    5         INTEGER IF(ISZ),   IT(ISZ),    OINDEX(ISZ),
             &        SIZE  ,DBSIZE,SYSIN ,PCIN  ,TTYIN ,DBASE ,TTYOUT,SYSOUT
    6         LOGICAL DBCORE,WCORE,INFEET,UWATER,PXDEF
    7         CHARACTER*4  OPTS(NOPTS),OPTION
    8         CHARACTER*6  STA(ISZ)
    9         CHARACTER*48 TITLE,OPTDAT
   10         COMMON /TITL / TITLE
   11         COMMON /PARMS/ SYSIN ,PCIN  ,TTYIN ,DBASE ,TTYOUT,SYSOUT,LINES
   12         COMMON /SIZES/ SIZE  ,DBSIZE,NO    ,LISTLN
   13         COMMON /FLAGS/ DBCORE,WCORE
   14         COMMON /PXBLK/ PXMIN, PXMAX, PXDEF
   15         COMMON /SUBLK/ VERSHN,INFEET,UWATER,LENGTH,PLANLN,DEC,CLINO
   16         DATA OINDEX,IF,IT,STA/1,ISZM1*0,ISZ*0,ISZ*0,ISZ*'      '/
   17         DATA E,N,H,DIST,EAST,NORTH,HEIGHT/ISZ7*0.0/
   18         DATA OPTS/'EXIT','DATA','ROSE','PLAN','ELEV'/
   19     100 WRITE(TTYOUT,5000) VERSHN
        C     OPTDAT = '                                                '
   20         READ(TTYIN,3000) OPTION,OPTDAT
   21         IF    ( OPTION .EQ. OPTS(1) ) THEN
   22              WRITE(TTYOUT,5001) VERSHN
   23              STOP
   24         ELSE IF ( OPTION.EQ.OPTS(2) ) THEN
   25              CALL SU(E,N,H,EAST,NORTH,HEIGHT,DIST,IF,IT,STA,OINDEX,SCRTCH)
   26         ELSE IF ( OPTION.EQ.OPTS(3) ) THEN
   27              CALL ROSE
   28         ELSE IF ( OPTION.EQ.OPTS(4) ) THEN
   29              CALL PPLAN(EAST,NORTH,HEIGHT,IF,IT,STA,PX,PY)
   30         ELSE IF ( OPTION.EQ.OPTS(5) ) THEN
   31              CALL PELEV(EAST,NORTH,HEIGHT,IF,IT,STA,PX)
   32         ELSE
   33              WRITE(TTYOUT,5002)
   34              GOTO 100
   35         ENDIF
   36         WRITE(TTYOUT,5003) OPTION
   37         GOTO 100
        C
   38    3000 FORMAT(A4,A48)
   39    5000 FORMAT(' SURVEY VERSION ',F4.2,': ENTER COMMANDS')
   40    5001 FORMAT(' SURVEY VERSION ',F4.2,' COMPLETED')
   41    5002 FORMAT(' OPTION ',A4,' UNKNOWN OR NOT IMPLEMENTED IN SU',F4.2)
   42    5003 FORMAT(' ',A4,' COMPLETED.')
   43         END
1       COMMON DATA INTIALISATION : SUINIT
+       __________________________________
0       *....*...1.........2.........3.........4.........5.........6.........7.*.......8
0   1         BLOCK DATA SUINIT
    2         PARAMETER ( ISZ=1008 )
    3         REAL    LENGTH
    4         INTEGER SIZE  ,DBSIZE,SYSIN ,PCIN  ,TTYIN ,DBASE ,TTYOUT,SYSOUT
    5         LOGICAL DBCORE,WCORE, INFEET,UWATER,PXDEF
    6         CHARACTER*48   TITLE
    7         COMMON /TITL / TITLE
    8         COMMON /SIZES/ SIZE  ,DBSIZE,NO    ,LISTLN
    9         COMMON /PARMS/ SYSIN ,PCIN  ,TTYIN ,DBASE ,TTYOUT,SYSOUT,LINES
   10         COMMON /FLAGS/ DBCORE,WCORE
   11         COMMON /PXBLK/ PXMIN,PXMAX,PXDEF
   12         COMMON /SUBLK/ VERSHN,INFEET,UWATER,LENGTH,PLANLN,DEC,CLINO
   13         DATA SIZE,SYSIN,PCIN,TTYIN,DBASE,TTYOUT,SYSOUT/ISZ,1,2,3,4,5,6/
   14         DATA LINES,DBCORE,INFEET,UWATER,PXDEF,VERSHN/40,4*.FALSE.,5.13/
   15         DATA LISTLN,LENGTH,PLANLN/1,0.,0./
   16         DATA TITLE/'                                                '/
   17         END
1       DATA REDUCTION ROUTINE : SU
+       ___________________________
0       *....*...1.........2.........3.........4.........5.........6.........7.*.......8
0   1         SUBROUTINE SU( E,N,H, EAST,NORTH,HEIGHT,DIST,
             &               IF,IT,STA, OINDEX, DEPTH )
        C
        C     VERSION 5.11                                        1983.10.25
        C     VERSION 5.12 TO INCORPORATE UNDERWATER SURVEY       1983.11.09
        C     VERSION 5.13 SPLIT OFF VECTOR CONVERSION TO CONVEC  1983.11.14
        C
    2         INTEGER SIZE,DBSIZE,SYSIN,PCIN,TTYIN,DBASE,TTYOUT,SYSOUT,OCOUNT
    3         INTEGER IF(SIZE),IT(SIZE),OINDEX(SIZE)
    4         LOGICAL DBCORE,WCORE ,INFEET,UWATER
    5         REAL       E(SIZE),    N(SIZE),     H(SIZE),  DIST(SIZE)
    6         REAL    EAST(SIZE),NORTH(SIZE),HEIGHT(SIZE), DEPTH(SIZE)
    7         REAL    LEG,       LENGTH,     PLANLN
    8         CHARACTER*1  REPLY ,NEGATV
    9         CHARACTER*6  FROM  ,TO    ,ORIGIN,CHANGE,END   ,FEET  ,METRIC,
             &             DIVING,NORMAL,       STA(SIZE)
   10         CHARACTER*48 TITLE
   11         COMMON /TITL / TITLE
   12         COMMON /PARMS/ SYSIN ,PCIN  ,TTYIN ,DBASE ,TTYOUT,SYSOUT,LINES
   13         COMMON /SIZES/ SIZE  ,DBSIZE,NO    ,LISTLN
   14         COMMON /FLAGS/ DBCORE,WCORE
   15         COMMON /SUBLK/ VERSHN,INFEET,UWATER,LENGTH,PLANLN,DEC,CLINO
        C
        C      INITIALIZE VARIABLES
        C
   16         DATA NEGATV / 'N' /,OCOUNT / 1 /,
             &  ORIGIN , END    , CHANGE , FEET   , METRIC , DIVING , NORMAL
             &/'ORIGIN','END   ','CHANGE','FEET  ','METRIC','DIVING','NORMAL'/
   17         IF ( DBCORE ) THEN
   18            WRITE(TTYOUT,5000)
   19            READ(TTYIN,5001)REPLY
   20            IF(REPLY.EQ.NEGATV) RETURN
   22            OCOUNT = 1
   23            LENGTH = 0.
   24            PLANLN = 0.
   25            LISTLN = 1
   26            DO 150 I=2,SIZE
   27     150    OINDEX(I) = 0
   28         ENDIF
   29         J = 0
        C
        C***********************************************************************
        C
        C           C O D E
        C
   30         READ(SYSIN,'(A48)')TITLE
        C
        C     TITLE : TITLE FOR THIS CASE, TO BE PRINTED ON OUTPUT
        C
   31         READ(SYSIN,1004) STA(1),EAST(1),NORTH(1),HEIGHT(1)
        C
        C----------------R E A D   L O O P--------------------------------------
        C
   32         DO 400 I = 1,SIZE
        C
   33     300    READ(SYSIN,1002)FROM,TO,LEG,BEAR,ELEV,VERT
        C
        C        TRAP END OF DATA
        C
   34            IF( FROM .EQ. END    ) GOTO 500
        C
        C        TRAP CHANGES OF CALIBRATION, RECALIBRATE AND READ NEXT LOT
        C         OF DATA WITHOUT ADVANCING I.
        C
   35            IF( FROM .NE. CHANGE ) GOTO 301
        C
        C     DEC : CORRECTION FOR MAGNETIC NORTH / COMPASS ERROR
        C     CLINO : CORRECTION FOR CLINOMETER ERROR
        C
   36               DEC    = BEAR
   37               CLINO  = ELEV
   38               CALL SHEAD(J)
   39               WRITE(SYSOUT,6004) DEC,CLINO
   40               GOTO 300
        C
        C        TRAP CHANGE OF UNITS
        C
   41     301    IF( FROM .NE. FEET   ) GOTO 302
   42               INFEET = .TRUE.
   43               GOTO 300
   44     302    IF( FROM .NE. METRIC ) GOTO 303
   45               INFEET = .FALSE.
   46               GOTO 300
        C
        C        TRAP CHANGE OF SURVEY FORMAT
        C
   47     303    IF( FROM .NE. DIVING ) GOTO 304
   48               UWATER = .TRUE.
   49               CALL SCAN1(STA,TO,ISURF)
   50               IF( ISURF.LT.0 ) CALL KILL(1)
   52               DEPTH(ISURF) = 0.0
   53               GOTO 300
   54     304    IF( FROM .NE. NORMAL ) GOTO 310
   55               UWATER = .FALSE.
   56               GOTO 300
        C
        C     TRAP DEFINITION OF NEW ORIGIN
        C
   57     310 IF( FROM .NE. ORIGIN ) GOTO 320
   58            NL = LISTLN + 1
   59            READ(SYSIN,1004) STA(NL),EAST(NL),NORTH(NL),HEIGHT(NL)
   60            CALL SCAN1(STA,STA(NL),IS)
   61            IF( IS .GT. 0 ) CALL KILL(2)
   63            LISTLN = NL
   64            OCOUNT = OCOUNT + 1
   65            OINDEX(LISTLN) = OCOUNT
   66            GOTO 300
   67     320    CALL CONVEC( STA, FROM,TO, LEG,BEAR,ELEV,VERT,
             &        DIST(I),E(I),N(I),H(I), IF(I),IT(I), DEPTH ,J )
   68     400 CONTINUE
        C
        C------------- E N D   O F   R E A D   L O O P -------------------------
        C
        C      ONLY REACH HERE IF MORE LEGS THAN PROGRAM DESIGNED FOR.
        C      REDEFINE I FOR USE OUTSIDE LOOP
        C
   69         READ(SYSIN,1002)FROM,TO
   70         IF(FROM.NE.END) WRITE(TTYOUT,5002)FROM,TO
   72         I = SIZE + 1
        C
        C     ALL DATA NOW READ IN AND LIST OF SURVEY STATIONS COMPLETE.
        C     GENERATE COORDINATES, PRINT STATISTICS AND STORE DATA.
        C
   73     500 REWIND SYSIN
   74         NO = I - 1
   75         CALL COORDS(E,N,H,DIST,EAST,NORTH,HEIGHT,IF,IT,STA,OINDEX)
   76         WRITE(SYSOUT,6005)PLANLN,LENGTH
   77         DBSIZE = 24 * ( 1 + ( LISTLN - 1 ) / 24 )
   78         CALL DBOUT(STA,IF,IT,EAST,NORTH,HEIGHT)
   79         RETURN
        C
        C***********************************************************************
        C
        C            I N P U T   &   O U T P U T   F O R M A T S
        C
   80    1002 FORMAT(2A6,F6.2,2F6.1,F6.2)
   81    1004 FORMAT(A6,6X,3F12.3)
        C
   82    5000 FORMAT(' SURVEY DATABASE IS ALREADY IN MEMORY.'/
             &       ' DO YOU WISH TO REDEFINE IT ?'         )
   83    5001 FORMAT(A1)
   84    5002 FORMAT(' *** WARNING ***  SURVEY LEG FROM ',A6,' TO ',
             &    A6,' EXCEEDS AVAILABLE DATA SPACE.'              )
        C
   85    6004 FORMAT(2X,'CALIBRATION :',16X,2F8.1)
   86    6005 FORMAT(1X//'  TOTAL PLAN LENGTH OF SURVEY : ',F9.3/
             +           '  TOTAL TRAVERSE LENGTH : ',     F15.3)
   87         END
1       VECTOR CONVERSION ROUTINE : CONVEC
+       __________________________________
0       *....*...1.........2.........3.........4.........5.........6.........7.*.......8
0   1         SUBROUTINE CONVEC( STA, FROM,TO, LEG,BEAR,ELEV,VERT,
             &                   DIST, E,N,H, IF,IT, DEPTH ,J )
        C
        C     VERSION 1.00 TO CONVERT DATA TO VECTOR FORM          1983.11.14
        C
    2         INTEGER SIZE,DBSIZE,SYSIN,PCIN,TTYIN,DBASE,TTYOUT,SYSOUT,OCOUNT
    3         LOGICAL INFEET,    UWATER
    4         REAL    LEG,       LENGTH,     PLANLN,   DEPTH(SIZE),  N
    5         CHARACTER*6  FROM  ,TO    ,STA(SIZE)
    6         CHARACTER*48 TITLE
    7         COMMON /TITL / TITLE
    8         COMMON /PARMS/ SYSIN ,PCIN  ,TTYIN ,DBASE ,TTYOUT,SYSOUT,LINES
    9         COMMON /SIZES/ SIZE  ,DBSIZE,NO    ,LISTLN
   10         COMMON /SUBLK/ VERSHN,INFEET,UWATER,LENGTH,PLANLN,DEC,CLINO
   11         DATA RAD/0.01745329/
        C
        C     CONVERT DATA TO VECTOR FORM :
        C
   12         CALL LIST( STA,FROM,TO,IF,IT,NFLAG )
   13         IF( INFEET ) THEN
   14            LEG  = LEG  * 0.3048
   15            VERT = VERT * 0.3048
   16            IF( UWATER ) ELEV = ELEV * 0.3048
   18         ENDIF
        C
        C     FROM : SURVEY STATION AT START OF LEG
        C     TO   : SURVEY STATION AT END OF LEG
        C     LEG  : LENGTH OF LEG
        C     BEAR : COMPASS BEARING
        C     DIST : PLAN LENGTH
        C     E,N,H : EAST,NORTH,VERTICAL COMPONENTS OF VECTOR
        C
   19         IF ( UWATER ) THEN
        C
        C        ELEV : DEPTH OF STATION FROM
        C        VERT : DEPTH OF STATION TO
        C        DEPTH : USED AS SCRATCH STORE FOR DEPTH UNDERWATER.
        C
   20            IF ( NFLAG .NE. 0 ) THEN
   21               IF ( IT .GT. IF ) THEN
   22                   DEPTH(IT) = VERT
   23               ELSE
   24                   DEPTH(IF) = ELEV
   25               ENDIF
   26            ENDIF
   27            IF ( ELEV * VERT .EQ. 0 ) THEN
        C      ****************************************************************
        C      * WARNING - THIS COULD FAIL FOR LOOPS CLOSING TO WATER SURFACE *
        C      ****************************************************************
   28                H = DEPTH(IF) - DEPTH(IT)
   29            ELSE
   30                H = ELEV - VERT
   31            ENDIF
   32            DIST = SQRT ( LEG * LEG - H * H )
   33            LENGTH = LENGTH + LEG
   34         ELSE
        C
        C        ELEV : INCLINATION OF LEG
        C        VERT : ANY VERTICAL COMPONENT PRODUCED BY PLUMBING
        C
   35            ELEV2   = ( ELEV - CLINO ) * RAD
   36            H       = LEG     * SIN(ELEV2) + VERT
   37            DIST    = LEG     * COS(ELEV2)
   38            LENGTH  = LENGTH  + LEG + ABS(VERT)
   39         ENDIF
   40         BEAR2 = ( BEAR - DEC ) * RAD
   41         E       = DIST   * SIN(BEAR2)
   42         N       = DIST   * COS(BEAR2)
   43         PLANLN  = PLANLN + DIST
        C
        C     OUTPUT NEW SET OF HEADINGS AFTER LINES LEGS ON ONE PAGE :
        C
   44         CALL SHEAD(J)
   45         IF ( UWATER ) THEN
   46            WRITE(SYSOUT,6002) FROM,TO,LEG,BEAR,H,DIST,E,N,H
   47         ELSE
   48            WRITE(SYSOUT,6003) FROM,TO,LEG,BEAR,ELEV,VERT,DIST,E,N,H
   49         ENDIF
   50         RETURN
   51    6002 FORMAT(2X,2A8,5X,F8.2,F8.1,'  UWATER',F8.2,10X,4F8.3)
   52    6003 FORMAT(2X,2A8,5X,F8.2,2F8.1,F8.2,10X,4F8.3)
   53         END
1       SU HEADINGS CONTROL ROUTINE : SHEAD
+       ___________________________________
0       *....*...1.........2.........3.........4.........5.........6.........7.*.......8
0   1         SUBROUTINE SHEAD(J)
        C     VERSION 1.00 TO ENABLE SU/CONVEC SPLIT.              1983.11.14
    2         INTEGER        SYSIN ,PCIN  ,TTYIN ,DBASE ,TTYOUT,SYSOUT
    3         CHARACTER*48   TITLE
    4         COMMON /TITL / TITLE
    5         COMMON /PARMS/ SYSIN ,PCIN  ,TTYIN ,DBASE ,TTYOUT,SYSOUT,LINES
    6         COMMON /SUBLK/ VERSHN,INFEET,UWATER,LENGTH,PLANLN,DEC,CLINO
    7         J = J + 1
    8         IF( MOD(J,LINES) .EQ. 1 ) WRITE(SYSOUT,6001) VERSHN,TITLE
   10         RETURN
   11    6001 FORMAT('1'//16X,'SU',F6.2,' : ',A48
             + //23X,'SURVEY DATA',31X,'COMPUTED VECTOR'/23X,32('-'),10X,32('-')
             + /5X,'FROM      TO',8X,'TAPE   COMPASS  CLINO   PLUMB',13X,'PLAN'
             + ,5X,'EAST   NORTH   HEIGHT'/)
   12         END
1       SURVEY STATION LIST CREATION : LIST
+       ___________________________________
0       *....*...1.........2.........3.........4.........5.........6.........7.*.......8
0   1         SUBROUTINE LIST(STA,FROM,TO,IF,IT,NFLAG)
        C
        C     SUBROUTINE TO CREATE AND EXTEND LIST OF STATION NAMES
        C     VERSION 1.01 ALSO GENERATES INDEX LIST IF,IT 1983.01.11
        C     VERSION 1.11 FORTRAN77 SU5.1                 1983.10.26
        C     VERSION 1.20 RETURNS NFLAG FOR SU5.12        1983.11.11
        C
    2         INTEGER SIZE,DBSIZE
    3         CHARACTER*6 FROM,TO,STA(SIZE)
    4         COMMON /SIZES/ SIZE,DBSIZE,NO,LISTLN
    5         CALL SCAN(STA,FROM,TO,IF,IT)
    6         NFLAG = 0
    7         IF(IF.LE.0) THEN
    8           LISTLN = LISTLN + 1
    9           NFLAG = 1
   10           STA(LISTLN) = FROM
   11           IF = LISTLN
   12         ENDIF
   13         IF(IT.LE.0) THEN
   14           LISTLN = LISTLN + 1
   15           NFLAG = NFLAG + 1
   16           STA(LISTLN) = TO
   17           IT = LISTLN
   18         ENDIF
   19         RETURN
   20         END
1       SURVEY STATION LIST SEARCH : SCAN
+       _________________________________
0       *....*...1.........2.........3.........4.........5.........6.........7.*.......8
0   1         SUBROUTINE SCAN(STA,FROM,TO,IF,IT)
        C
        C     SUBROUTINE TO SEARCH LIST OF STATIONS
        C     VERSION 1.20 FORTRAN77 FASTER SEARCH               1983.10.26
        C
    2         INTEGER SIZE,DBSIZE
    3         CHARACTER*6 FROM,TO,STA(LISTLN)
    4         COMMON /SIZES/ SIZE,DBSIZE,NO,LISTLN
    5         IF = -1
    6         IT = -1
    7         IFOUND = -2
    8         DO 1 I = LISTLN,1,-1
    9           IF   ( STA(I) .EQ. FROM ) THEN
   10              IF = I
   11              IFOUND = IFOUND + 1
   12           ELSE IF( STA(I) .EQ. TO ) THEN
   13              IT = I
   14              IFOUND = IFOUND + 1
   15           ENDIF
   16           IF(IFOUND.EQ.0) RETURN
   18       1 CONTINUE
   19         RETURN
   20         END
1       FAST SINGLE SURVEY STATION LIST SEARCH : SCAN1
+       ______________________________________________
0       *....*...1.........2.........3.........4.........5.........6.........7.*.......8
0   1         SUBROUTINE SCAN1(STA,SEARCH,IS)
        C
        C     FAST SEARCH FOR SINGLE STATION, FROM SCAN 1.20     1983.11.11
        C
    2         INTEGER SIZE,DBSIZE
    3         CHARACTER*6 SEARCH,STA(LISTLN)
    4         COMMON /SIZES/ SIZE,DBSIZE,NO,LISTLN
    5         DO 1 I = LISTLN,1,-1
    6           IF   ( STA(I) .EQ. SEARCH ) GOTO 2
    7       1 CONTINUE
    8         IS = -1
    9         RETURN
   10       2 IS = I
   11         RETURN
   12         END
1       COORDINATE CALCULATION : COORDS
+       _______________________________
0       *....*...1.........2.........3.........4.........5.........6.........7.*.......8
0   1         SUBROUTINE COORDS(E,N,H,DIST,EAST,NORTH,HEIGHT,IF,IT,STA,OINDEX)
        C
        C     COORDS 1.00  FOR SU 4.2  1982.08.24  WITH BACKSIGHTS
        C     COORDS 2.00         5.00 1983.01.13  'SURVEY' IMPLEMENTATION
        C     COORDS 2.10         5.10 1983.01.28 MULTIPLE ORIGINS
        C     COORDS 2.13              1983.10.26 CHEAD INTERFACE AGAIN
        C
    2         INTEGER SIZE,DBSIZE,SYSIN,PCIN,TTYIN,DBASE,TTYOUT,SYSOUT,OCURR
    3         INTEGER   IF(SIZE),   IT(SIZE),OINDEX(SIZE)
    4         REAL       E(SIZE),    N(SIZE),     H(SIZE),  DIST(SIZE)
    5         REAL    EAST(SIZE),NORTH(SIZE),HEIGHT(SIZE)
    6         REAL    MISCE,     MISCN,      MISCH,       LENGTH
    7         LOGICAL DBCORE,WCORE, INFEET,UWATER
    8         CHARACTER*6 STA(SIZE)
    9         CHARACTER*48 TITLE
   10         COMMON /TITL / TITLE
   11         COMMON /PARMS/ SYSIN ,PCIN  ,TTYIN ,DBASE ,TTYOUT,SYSOUT,LINES
   12         COMMON /SIZES/ SIZE  ,DBSIZE,NO    ,LISTLN
   13         COMMON /FLAGS/ DBCORE,WCORE
   14         COMMON /SUBLK/ VERSHN,INFEET,UWATER,LENGTH,PLANLN,DEC,CLINO
   15         OCURR = 0
   16         J = 0
        C
   17         DO 590 I = 1,NO
   18           IF(OINDEX(IF(I)).GT.0) GOTO 510
   19           IF(OINDEX(IT(I)).GT.0) GOTO 520
        C         LEG IS ISOLATED FROM REST OF SURVEY.
   20             CALL CHEAD(J,1)
   21             WRITE(SYSOUT,2010)STA(IF(I)),STA(IT(I)),E(I),N(I),H(I),DIST(I)
   22             GOTO 590
   23     510   IF(OINDEX(IT(I)).GT.0) GOTO 550
        C       FORWARD SIGHTING LEG :
   24           A = 1.
   25           ID = IF(I)
   26           IU = IT(I)
   27           GOTO 530
        C
        C       BACKSIGHT :
   28     520   A = -1.
   29           ID = IT(I)
   30           IU = IF(I)
   31     530   EAST(  IU) = EAST(  ID) + A * E(I)
   32           NORTH( IU) = NORTH( ID) + A * N(I)
   33           HEIGHT(IU) = HEIGHT(ID) + A * H(I)
   34           OINDEX(IU) = OINDEX(ID)
   35           IF (OINDEX(ID).GT.OCURR) THEN
   36              CALL CHEAD(J,2)
   37              OCURR = OINDEX(ID)
   38              WRITE(SYSOUT,2004)OCURR,STA(ID),EAST(ID),NORTH(ID),HEIGHT(ID)
   39           ELSE
   40              CALL CHEAD(J,1)
   41           ENDIF
   42           WRITE(SYSOUT,2003)STA(IF(I)),STA(IT(I)),E(I),N(I),H(I),DIST(I),
             &                    STA( IU  ),EAST(IU),NORTH(IU),HEIGHT(IU)
   43           GOTO 590
        C       BOTH ENDS OF LEG ALREADY DEFINED.
   44     550   MISCE = EAST(  IF(I)) + E(I) - EAST(IT(I))
   45           MISCN = NORTH( IF(I)) + N(I) - NORTH(IT(I))
   46           MISCH = HEIGHT(IF(I)) + H(I) - HEIGHT(IT(I))
   47           IF(OINDEX(IF(I)).NE.OINDEX(IT(I))) THEN
   48             IF(MAX(OINDEX(IF(I)),OINDEX(IT(I))).GT.OCURR) THEN
   49              CALL CHEAD(J,3)
   50              IO = IF(I)
   51              IF(OINDEX(IT(I)).GT.OINDEX(IO)) IO = IT(I)
   53              OCURR = OINDEX(IO)
   54              WRITE(SYSOUT,2004)OCURR,STA(IO),EAST(IO),NORTH(IO),HEIGHT(IO)
   55             ELSE
   56              CALL CHEAD(J,2)
   57             ENDIF
   58     558     WRITE(SYSOUT,2007) OINDEX(IF(I)),OINDEX(IT(I))
   59           ELSE
   60             CALL CHEAD(J,1)
   61           ENDIF
   62     570   WRITE(SYSOUT,2006) STA(IF(I)),STA(IT(I)),E(I),N(I),H(I),DIST(I),
             &                     MISCE,MISCN,MISCH
   63     590 CONTINUE
   64         DBCORE = .TRUE.
   65         RETURN
   66    2003 FORMAT( 1X,A6,A8,4F9.3,5X,A8,3F10.3)
   67    2004 FORMAT(40X,'ORIGIN',I4,'  AT  ',A8,3F10.3)
   68    2006 FORMAT( 1X,A6,A8,4F9.3,4X,'MISCLOSES',3F10.3)
   69    2007 FORMAT(15X,'SURVEYS',I4,' AND',I4,' CONNECT :')
   70    2010 FORMAT(1X,A6,A8,4F9.3,4X,'UNDEFINED')
   71         END
1       COORDINATE OUTPUT FORMATTING : CHEAD
+       ____________________________________
0       *....*...1.........2.........3.........4.........5.........6.........7.*.......8
0   1         SUBROUTINE CHEAD(J,I)
        C
        C     SUBROUTINE TO PRINT COORDS HEADINGS IF NEEDEDV 1.03  83.10.26
        C
        C     J = NO. OF LINES OUTPUT SO FAR.  I = SPARE LINES NEEDED THIS PAGE
        C
    2         CHARACTER*48 TITLE
    3         INTEGER UNITS(5),SYSOUT
    4         COMMON /TITL / TITLE
    5         COMMON /PARMS/ UNITS ,SYSOUT,LINES
    6         COMMON /SUBLK/ VERSHN,INFEET,UWATER,LENGTH,PLANLN,DEC,CLINO
        C
    7         DO 100 K = 0,I-1
    8            IF(MOD(J+K,LINES).EQ.0) GOTO 200
    9     100 CONTINUE
   10         J = J + I
   11         RETURN
   12     200 WRITE(SYSOUT,2009) VERSHN,TITLE
   13         J = J + K + I
   14         RETURN
   15    2009 FORMAT('1'//' SU',F6.2,25X,A48 //
             & 22X,'VECTOR',45X,'POSITION' / 2X,49('-'),5X,38('-') /
             & 3X,'FROM     TO     EAST    NORTH    HEIGHT',
             & 4X,'PLAN',7X,'STATION     EAST     NORTH     HEIGHT'/)
   16         END
1       DATABASE CREATION : DBOUT
+       _________________________
0       *....*...1.........2.........3.........4.........5.........6.........7.*.......8
0   1         SUBROUTINE DBOUT(STA,IF,IT,EAST,NORTH,HEIGHT)
        C
    2         INTEGER SIZE,DBSIZE,SYSIN,PCIN,TTYIN,DBASE,TTYOUT,SYSOUT
    3         INTEGER IF(DBSIZE),IT(DBSIZE)
    4         REAL EAST(DBSIZE),NORTH(DBSIZE),HEIGHT(DBSIZE)
    5         CHARACTER*6 STA(DBSIZE)
    6         CHARACTER*48 TITLE
    7         COMMON /TITL / TITLE
    8         COMMON /PARMS/ SYSIN,PCIN,TTYIN,DBASE,TTYOUT,SYSOUT,LINES
    9         COMMON /SIZES/ SIZE,DBSIZE,NO,LISTLN
        C
   10         WRITE(DBASE,4000) TITLE,DBSIZE,NO,LISTLN
   11         WRITE(DBASE,4001) STA
   12         WRITE(DBASE,4002) IF,IT
   13         WRITE(DBASE,4003) EAST,NORTH,HEIGHT
   14         RETURN
   15    4000 FORMAT(1X,A48/1X,3I6)
   16    4001 FORMAT(1X,12A6)
   17    4002 FORMAT(1X,12I6)
   18    4003 FORMAT(1X,8F10.3)
   19         END
1       CREATE PLAN PLOT DATA : PPLAN
+       _____________________________
0       *....*...1.........2.........3.........4.........5.........6.........7.*.......8
0   1         SUBROUTINE PPLAN(EAST,NORTH,HEIGHT,IF,IT,STA,PX,PY)
        C
        C     TO INTERROGATE DATABASE AND PLOT SURVEY PLAN.
        C     VERSION 2.00
        C
    2         INTEGER SIZE,DBSIZE,SYSIN,PCIN,TTYIN,DBASE,TTYOUT,SYSOUT
    3         INTEGER IF(SIZE),IT(SIZE)
    4         REAL    EAST(SIZE),NORTH(SIZE),HEIGHT(SIZE),WRANGE(2,3)
    5         REAL    PX(SIZE),PY(SIZE)
    6         LOGICAL DBCORE,WCORE,PXDEF
    7         CHARACTER*6  STA(SIZE)
    8         CHARACTER*48 TITLE
    9         COMMON / TITL/ TITLE
   10         COMMON /PARMS/ SYSIN, PCIN,  TTYIN, DBASE, TTYOUT,SYSOUT,LINES
   11         COMMON /SIZES/ SIZE,  DBSIZE,NO,    LISTLN
   12         COMMON /FLAGS/ DBCORE,WCORE
   13         COMMON /PXBLK/ PXMIN, PXMAX, PXDEF
   14         READ(PCIN,1001)SCALE, ORIENT,WRANGE
   15         REWIND PCIN
   16         IF(DBCORE) GOTO 100
   17         READ(DBASE,2001)TITLE,DBSIZE,NO,LISTLN
   18         CALL DBREAD(STA,IF,IT,EAST,NORTH,HEIGHT)
   19     100 CALL PLAN(SCALE,ORIENT,WRANGE,STA,IF,IT,EAST,NORTH,PX,PY)
   20         RETURN
   21    1001 FORMAT(2F6.0,6F8.0)
   22    2001 FORMAT(1X,A48/1X,3I6)
   23         END
1       SEND PLAN DATA TO GRAPHICS INTERFACE ROUTINE : PLAN
+       ___________________________________________________
0       *....*...1.........2.........3.........4.........5.........6.........7.*.......8
0   1         SUBROUTINE PLAN(SCALE,ANGLE,WRANGE,STA,IF,IT,EAST,NORTH,PX,PY)
        C
        C     SUBROUTINE TO PLOT A SURVEY FROM SAVED COORDINATE DATA AT A USER
        C     DEFINED SCALE, INTO A USER ORIENTATED AND SIZED WINDOW AREA.
        C
        C     VERSION 1.00  A.E.R.WADDINGTON                         1982.09.07
        C     VERSION 1.10  FOR SU 5 SUITE                           1983.01.11
        C     VERSION 1.20  PACKAGE INDEPENDENT PLOT                 1983.08.26
        C
    2         INTEGER SIZE,DBSIZE,SYSIN,PCIN,TTYIN,DBASE,TTYOUT,SYSOUT
    3         INTEGER IF(NO),IT(NO)
    4         REAL WRANGE(2,3),EAST(LISTLN),NORTH(LISTLN),PX(LISTLN),PY(LISTLN)
    5         LOGICAL PXDEF
    6         CHARACTER*6 STA(LISTLN)
    7         CHARACTER*48 TITLE
    8         COMMON /TITL / TITLE
    9         COMMON /PARMS/ SYSIN, PCIN,  TTYIN, DBASE, TTYOUT,SYSOUT,LINES
   10         COMMON /SIZES/ SIZE,  DBSIZE,NO,    LISTLN
   11         COMMON /PXBLK/ PXMIN, PXMAX, PXDEF
   12         DATA RAD/.01745329/
        C
        C     CONVERT SURVEY SPACE COORDINATES TO PAPER-SPACE COORDINATES WITH
        C     PLOTTER X-AXIS ALIGNED ON A BEARING OF <ANGLE>, AND CALCULATE
        C     RANGE OF X AND Y COORDINATES.
        C
   13         BE = RAD * ANGLE
   14         SINB = SIN(BE)
   15         COSB = COS(BE)
   16         IF(PXDEF) GOTO 100
   17            PX(1) = NORTH(1) * COSB + EAST(1) * SINB
   18            PXMAX      = PX(1)
   19            PXMIN      = PXMAX
   20     100 PY(1) = NORTH(1) * SINB - EAST(1) * COSB
   21         PYMAX      = PY(1)
   22         PYMIN      = PYMAX
   23         DO 150 I = 2,LISTLN
   24            IF(PXDEF) GOTO 140
   25               PX(I) = NORTH(I) * COSB + EAST(I) * SINB
   26               IF(PX(I).LT.PXMIN) PXMIN = PX(I)
   28               IF(PX(I).GT.PXMAX) PXMAX = PX(I)
   30     140    PY(I) = NORTH(I) * SINB - EAST(I) * COSB
   31            IF(PY(I).LT.PYMIN) PYMIN = PY(I)
   33            IF(PY(I).GT.PYMAX) PYMAX = PY(I)
   35     150 CONTINUE
   36         WRITE(SYSOUT,2004) ANGLE,PYMIN,PYMAX,PXMIN,PXMAX
             &            ,WRANGE(1,2),WRANGE(2,2),WRANGE(1,1),WRANGE(2,1)
   37         WRITE(TTYOUT,2004) ANGLE,PYMIN,PYMAX,PXMIN,PXMAX
             &            ,WRANGE(1,2),WRANGE(2,2),WRANGE(1,1),WRANGE(2,1)
   38         IF(     PYMAX.GT.WRANGE(2,2)  .OR.  PYMIN.LT.WRANGE(1,2)
             &    .OR.PXMAX.GT.WRANGE(2,1)  .OR.  PXMIN.LT.WRANGE(1,1) )
             &                      WRITE(TTYOUT,2005)
   40         WRITE(TTYOUT,*) I
   41         CALL PLOT(SCALE,WRANGE(1,1),WRANGE(1,2),PX,PY,IF,IT)
   42         RETURN
   43    2004 FORMAT('1'/' PAPER LONG AXIS IS ON A BEARING OF',F5.0,' DEGREES'//
             +' EXTENT OF SURVEY IN SCALE PAPER SPACE:'/'   WIDTH  AXIS',2F11.3/
             + '   LENGTH AXIS',2F11.3//
             +' EXTENT OF WINDOW IN SCALE PAPER SPACE:'/'   WIDTH  AXIS',2F11.3/
             + '   LENGTH AXIS',2F11.3//)
   44    2005 FORMAT('0 *** WARNING *** SURVEY EXTENDS BEYOND WINDOW AREA')
   45         END
1       CREATE ELEVATION PLOT DATA: PELEV
+       __________________________________
0       *....*...1.........2.........3.........4.........5.........6.........7.*.......8
0   1         SUBROUTINE PELEV(EAST,NORTH,HEIGHT,IF,IT,STA,PX)
        C
        C     TO INTERROGATE DATABASE AND PLOT SURVEY ELEVATION.
        C     VERSION 2.00
        C
    2         INTEGER SIZE,DBSIZE,SYSIN,PCIN,TTYIN,DBASE,TTYOUT,SYSOUT
    3         INTEGER IF(SIZE),  IT(SIZE)
    4         REAL    EAST(SIZE),NORTH(SIZE),HEIGHT(SIZE),PX(SIZE),WRANGE(2,3)
    5         LOGICAL DBCORE,WCORE,PXDEF
    6         CHARACTER*6 STA(SIZE)
    7         CHARACTER*48 TITLE
    8         COMMON / TITL/ TITLE
    9         COMMON /PARMS/ SYSIN, PCIN,  TTYIN, DBASE, TTYOUT,SYSOUT,LINES
   10         COMMON /SIZES/ SIZE,  DBSIZE,NO,    LISTLN
   11         COMMON /FLAGS/ DBCORE,WCORE
   12         COMMON /PXBLK/ PXMIN, PXMAX, PXDEF
   13         READ(PCIN,1001)SCALE, ORIENT,WRANGE
   14         REWIND PCIN
   15         IF(DBCORE) GOTO 100
   16         READ(DBASE,2001)TITLE,DBSIZE,NO,LISTLN
   17         CALL DBREAD(STA,IF,IT,EAST,NORTH,HEIGHT)
   18     100 CALL ELEV(SCALE,ORIENT,WRANGE,STA,IF,IT,EAST,NORTH,PX,HEIGHT)
   19         RETURN
   20    1001 FORMAT(2F6.0,6F8.0)
   21    2001 FORMAT(1X,A48/1X,3I6)
   22         END
1       SEND ELEVATION DATA TO GRAPHICS INTERFACE ROUTINE : ELEV
+       ________________________________________________________
0       *....*...1.........2.........3.........4.........5.........6.........7.*.......8
0   1         SUBROUTINE ELEV(SCALE,ANGLE,WRANGE,STA,IF,IT,EAST,NORTH,PX,HEIGHT)
        C
        C     SUBROUTINE TO PLOT A SURVEY FROM SAVED COORDINATE DATA AT A USER
        C     DEFINED SCALE, INTO A USER ORIENTATED AND SIZED WINDOW AREA.
        C
        C     VERSION 1.20  PACKAGE INDEPENDENT IMPLEMENTATION       1983.08.26
        C
    2         INTEGER SIZE,DBSIZE,SYSIN,PCIN,TTYIN,DBASE,TTYOUT,SYSOUT
    3         INTEGER IF(NO),IT(NO)
    4         REAL WRANGE(2,3),EAST(LISTLN),NORTH(LISTLN),HEIGHT(LISTLN),
             &                 PX(LISTLN)
    5         LOGICAL      PXDEF
    6         CHARACTER*6  STA(LISTLN)
    7         CHARACTER*48 TITLE
    8         COMMON / TITL/ TITLE
    9         COMMON /PARMS/ SYSIN, PCIN,  TTYIN, DBASE, TTYOUT,SYSOUT,LINES
   10         COMMON /SIZES/ SIZE,  DBSIZE,NO,    LISTLN
   11         COMMON /PXBLK/ PXMIN, PXMAX, PXDEF
   12         DATA RAD/.01745329/
        C
        C     CONVERT SURVEY SPACE COORDINATES TO PAPER-SPACE COORDINATES WITH
        C     PLOTTER X-AXIS ALIGNED ON A BEARING OF <ANGLE>, AND CALCULATE
        C     RANGE OF X AND Y COORDINATES.
        C
   13         BE = RAD * ANGLE
   14         SINB = SIN(BE)
   15         COSB = COS(BE)
   16         IF(PXDEF) GOTO 100
   17            PX(1)   = NORTH(1) * COSB + EAST(1) * SINB
   18            PXMAX   = PX(1)
   19            PXMIN   = PXMAX
   20     100 PZMAX      = HEIGHT(1)
   21         PZMIN      = PZMAX
   22         DO 150 I = 2,LISTLN
   23            IF(PXDEF) GOTO 140
   24               PX(I) = NORTH(I) * COSB + EAST(I) * SINB
   25               IF(PX(I).LT.PXMIN) PXMIN = PX(I)
   27               IF(PX(I).GT.PXMAX) PXMAX = PX(I)
   29     140    IF(HEIGHT(I).LT.PZMIN) PZMIN = HEIGHT(I)
   31            IF(HEIGHT(I).GT.PZMAX) PZMAX = HEIGHT(I)
   33     150 CONTINUE
   34         WRITE(SYSOUT,2004) ANGLE,PZMIN,PZMAX,PXMIN,PXMAX
             &            ,WRANGE(1,3),WRANGE(2,3),WRANGE(1,1),WRANGE(2,1)
   35         WRITE(TTYOUT,2004) ANGLE,PZMIN,PZMAX,PXMIN,PXMAX
             &            ,WRANGE(1,3),WRANGE(2,3),WRANGE(1,1),WRANGE(2,1)
   36         IF(    PZMAX.GT.WRANGE(2,3)  .OR.  PZMIN.LT.WRANGE(1,3)
             &   .OR.PXMAX.GT.WRANGE(2,1)  .OR.  PXMIN.LT.WRANGE(1,1) )
             &                      WRITE(TTYOUT,2005)
   38         CALL PLOT(SCALE,WRANGE(1,1),WRANGE(1,3),PX,HEIGHT,IF,IT)
   39         RETURN
   40    2004 FORMAT('1'/' PAPER LONG AXIS IS ON A BEARING OF',F5.0,' DEGREES'//
             +' EXTENT OF SURVEY IN SCALE PAPER SPACE:'/'   HEIGHT AXIS',2F11.3/
             +'   LENGTH AXIS',2F11.3//
             +' EXTENT OF WINDOW IN SCALE PAPER SPACE:'/'   HEIGHT AXIS',2F11.3/
             +'   LENGTH AXIS',2F11.3//)
   41    2005 FORMAT('0',' *** WARNING *** SURVEY EXTENDS BEYOND WINDOW AREA')
   42         END
1       DATABASE RETRIEVAL ROUTINE : DBREAD
+       ___________________________________
0       *....*...1.........2.........3.........4.........5.........6.........7.*.......8
0   1         SUBROUTINE DBREAD(STA,IF,IT,EAST,NORTH,HEIGHT)
        C
        C     TO RETRIEVE DATABASE FROM DISC. V 1.00     1983.  .
        C
    2         INTEGER SIZE,DBSIZE,SYSIN,PCIN,TTYIN,DBASE,TTYOUT,SYSOUT
    3         INTEGER IF(DBSIZE),IT(DBSIZE)
    4         REAL    EAST(DBSIZE),NORTH(DBSIZE),HEIGHT(DBSIZE)
    5         LOGICAL DBCORE,WCORE
    6         CHARACTER*6 STA(DBSIZE)
    7         COMMON /PARMS/ SYSIN, PCIN,  TTYIN, DBASE,TTYOUT,SYSOUT,LINES
    8         COMMON /SIZES/ SIZE,  DBSIZE,NO,    LISTLN
    9         COMMON /FLAGS/ DBCORE,WCORE
   10         READ(DBASE,3001)STA
   11         READ(DBASE,3002)IF,IT
   12         READ(DBASE,3003)EAST,NORTH,HEIGHT
   13         REWIND DBASE
   14         DBCORE = .TRUE.
   15         RETURN
   16    3001 FORMAT(1X,12A6)
   17    3002 FORMAT(1X,12I6)
   18    3003 FORMAT(1X,8F10.3)
   19         END
1       ROSE DIAGRAM CREATION : ROSE
+       ____________________________
0       *....*...1.........2.........3.........4.........5.........6.........7.*.......8
0   1         SUBROUTINE ROSE
        C
        C     VERSION 1.00 A.E.R.WADDINGTON                       1983.01.12
        C     VERSION 1.02 IMPLEMENTED USING ROSPLT AS INTERFACE  1983.08.30
        C
    2         INTEGER SIZE,DBSIZE,SYSIN,PCIN,TTYIN,DBASE,TTYOUT,SYSOUT
    3         REAL LEG,LENGTH,PLANLN,BELEN(45),BEFRCT(45),RANGE(0:45),INTSZ
    4         CHARACTER*6 FROM,    TO, START,   END,CHANGE,  FEET,METRIC,
             &                 ORIGIN,DIVING,NORMAL
    5         CHARACTER*48 TITLE
    6         LOGICAL INFEET,UWATER
    7         COMMON /TITL / TITLE
    8         COMMON /PARMS/ SYSIN,PCIN,TTYIN,DBASE,TTYOUT,SYSOUT,LINES
    9         COMMON /SIZES/ SIZE  ,DBSIZE,NO    ,LISTLN
        C
        C      INITIALIZE VARIABLES
        C
   10         DATA  INFEET, UWATER / 2* .FALSE. /,
             &  ORIGIN , END    , CHANGE , FEET   , METRIC , DIVING , NORMAL
             &/'ORIGIN','END   ','CHANGE','FEET  ','METRIC','DIVING','NORMAL'/,
             &  RAD , RANGE(0) , BELEN , RVERS  /.01745329 , 46*0. , 1.03/
   11         LENGTH = 0.
   12         PLANLN = 0.
        C
        C***********************************************************************
        C
        C           C O D E
        C
   13         WRITE(TTYOUT,5001)RVERS
   14         READ(TTYIN,*) INTSZ
   15         NINTS  = MIN( INT( 180. / INTSZ ) , 45 )
   16         INTSZ  = 180. / NINTS
   17         WRITE(TTYOUT,5002) RVERS, NINTS, INTSZ
   18         READ(SYSIN,'(A48)')TITLE
        C
   19         READ(SYSIN,'(A6)')START
        C
        C----------------R E A D   L O O P--------------------------------------
        C
   20         DO 400 I = 1,SIZE
        C
   21     300    READ(SYSIN,1002)FROM,TO,LEG,BEAR,ELEV,VERT
   22            IF( FROM .EQ. END    ) GOTO 500
   23            IF( FROM .NE. CHANGE ) GOTO 301
   24               DEC    = BEAR
   25               CLINO  = ELEV
   26               GOTO 300
   27     301    IF( FROM .NE. FEET   ) GOTO 302
   28               INFEET = .TRUE.
   29               GOTO 300
   30     302    IF( FROM .NE. METRIC ) GOTO 303
   31               INFEET = .FALSE.
   32               GOTO 300
   33     303    IF( FROM .NE. DIVING ) GOTO 304
   34               UWATER = .TRUE.
   35               GOTO 300
   36     304    IF( FROM .NE. NORMAL ) GOTO 310
   37               UWATER = .FALSE.
   38               GOTO 300
   39     310    IF( FROM .EQ. ORIGIN ) GOTO 300
        C
   40            BEAR1 = ( BEAR - DEC )
   41            BEAR2 = BEAR1 * RAD
   42            IF( INFEET ) THEN
   43                               LEG  = LEG  * 0.3048
   44                               VERT = VERT * 0.3048
   45                         ENDIF
   46            IF( UWATER ) THEN
        C                           THIS IS SOMEWHAT DUFF - BUT EASIER THAN
        C                           DOING IT PROPERLY AS IN SU
        C
   47                               DIST   = LEG
   48                               LENGTH = LENGTH + LEG
   49                         ELSE
   50                               ELEV2 = ( ELEV - CLINO ) * RAD
   51                               DIST   = LEG    * COS(ELEV2)
   52                               LENGTH = LENGTH + LEG + ABS(VERT)
   53                         ENDIF
   54            PLANLN = PLANLN + DIST
   55            ITEMP  = INT( BEAR1 / INTSZ )
   56            IBEAR  = 1 + MOD( NINTS + MOD( ITEMP , NINTS ), NINTS )
   57     400    BELEN(IBEAR) = BELEN(IBEAR) + DIST
        C
        C------------- E N D   O F   R E A D   L O O P -------------------------
        C
   58         I = SIZE + 1
   59     500 REWIND SYSIN
   60         WRITE(SYSOUT,6001) RVERS, TITLE, PLANLN, LENGTH
   61         DO 550 I = 1,NINTS
   62            RANGE(I) = INTSZ * REAL(I)
   63     550    BEFRCT(I) = 100. * BELEN(I) / PLANLN
   64         WRITE(SYSOUT,6002)(RANGE(I-1),RANGE(I),BELEN(I),BEFRCT(I)
             &                                        ,I=1,NINTS)
   65         CALL ROSPLT(INTSZ,NINTS,RANGE,BEFRCT)
   66         RETURN
        C
        C***********************************************************************
        C
   67    1002 FORMAT(2A6,F6.2,2F6.1,F6.2)
        C
   68    5001 FORMAT(' ROSE',F5.2,': SPECIFY INTERVAL SIZE ( DEGREES )')
   69    5002 FORMAT(' ROSE',F5.2,': USING',I3,' INTERVALS OF',F6.2,' DEGREES.')
        C
   70    6001 FORMAT('1'//' ROSE',F5.2,' : ',A48/
             & '  TOTAL  PLAN  LENGTH OF SURVEY : ',F9.3/
             & '  TOTAL  TRAVERSE  LENGTH : ',F15.3)
   71    6002 FORMAT('0 +------------------+------------+---------+'/
             &       '  |  BEARING  RANGE  | CUMULATIVE |         |'/
             &       '  |   OF  INTERVAL   |   LENGTH   | PERCENT |'/
             &       '  +------------------+------------+---------+'/
             &     ('  |',F7.2,' TO',F7.2,' |',F9.2,'   |',F8.3,' |'/
             &       '  +------------------+------------+---------+'))
   72         END
1       TERMINAL ERROR ROUTINE : KILL
+       _____________________________
0       *....*...1.........2.........3.........4.........5.........6.........7.*.......8
0   1         SUBROUTINE KILL(I)
        C
        C     SUBROUTINE TO TERMINATE IN ERROR CONDITIONS.
        C
    2         CHARACTER*50 MESAGE(10)
    3         DATA MESAGE
             &/ 'SURFACE STATION IN UNDERWATER SURVEY NOT DEFINED. ',
             &  'NEW ORIGIN ATTEMPTS TO REDEFINE EXISTING STATION. ',
             &  '                                                  ',
             &  '                                                  ',
             &  '                                                  ',
             &  '                                                  ',
             &  '                                                  ',
             &  '                                                  ',
             &  '                                                  ',
             &  '                                                  '/
    4         WRITE(5,5999) MESAGE(I)
    5         STOP
    6    5999 FORMAT(' FATAL ERROR : ',A50)
    7         END
