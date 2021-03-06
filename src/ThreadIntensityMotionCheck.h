#ifndef ThreadIntensityMotionCheck_H
#define ThreadIntensityMotionCheck_H

#include <QThread>

class Protocol;
class QCResult;

#include "IntensityMotionCheck.h"

class CThreadIntensityMotionCheck : public QThread
{
  Q_OBJECT
public:
  CThreadIntensityMotionCheck(QObject *parent = 0);
  ~CThreadIntensityMotionCheck();

  CIntensityMotionCheck * m_IntensityMotionCheck;    // pointer to the core function to show its long running for
                                                     // progressBar

  void SetDwiFileName(std::string filename)
  {
    DWINrrdFilename = filename;
  }

  void SetXmlFileName(std::string filename)
  {
    XmlFilename = filename;
  }

  void SetProtocol( Protocol *p)
  {
    protocol = p;
  }

  void SetQCResult( QCResult *r)
  {
    qcResult = r;
  }

  bool HasComputed() ;
  void SetHasComputed(bool computed){
    m_hasComputedOnce = computed;
  }
  void SetRecompute( bool val ) ;
  void SetRecomputeOutputFileName( std::string filename ) ;

signals:
  void allDone(const QString &);

  void ResultUpdate();

  void QCedResultUpdate();

  void Set_VCStatus();

  void Set_Original_ForcedConformance_Mapping();

  void Set_QCedDWI();

  void QQQ(int);

  void kkk( int );

  void StartProgressSignal();   // Signal for progressBar function

  void StopProgressSignal();   // Signal for progressBar function

  void Building_Mapping_XML();    // Signal to create mapping between conformanced gradeints and original gradeints

  void LoadQCedDWI( QString qcdwiname);

  void SignalRecomputationDone();

  void f_StartProgressSignal() ;

  void f_StopProgressSignal() ;

protected:
  void run();

private:
  std::string DWINrrdFilename;
  std::string XmlFilename;

  Protocol *protocol;
  QCResult *qcResult;

  bool m_hasComputedOnce ;
  bool m_Recompute ;
  std::string m_RecomputeOutputFileName ;
  // unsigned char result; // the result of RunPipelineByProtocol

};

#endif
