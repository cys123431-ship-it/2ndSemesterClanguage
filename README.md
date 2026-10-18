# 2학기 C언어 과제 — 1차 완성본 / 8~11장 응용판 / 상세 해설

이 저장소는 **C언어 Express 8~11장(함수·변수 범위와 재귀·배열·포인터)**을 수업에서 배운 범위로 삼아, 세 가지 C언어 과제를 스스로 설명할 수 있도록 정리한 학습용 저장소입니다.

**중요: 기존 1차 완성본의 코드 파일 5개는 수정하지 않았습니다.** 별도의 `Applied_8to11/` 폴더에 학습용 응용 버전을 추가했습니다. 설명 파일은 각 프로그램 폴더의 `EXPLANATION.md`입니다.

## 1. 파일 안내

| 프로그램 | 1차 완성본 코드 | 1차 완성본 자세한 해설 | 8~11장 응용판 코드 | 응용판 자세한 해설 |
|---|---|---|---|---|
| ① 점수 배열 | [main.c](01_ScoreArray/main.c) | [해설 MD](01_ScoreArray/EXPLANATION.md) | [main.c](Applied_8to11/01_ScoreArray/main.c) | [해설 MD](Applied_8to11/01_ScoreArray/EXPLANATION.md) |
| ② 영화관 좌석 예약 | [main.c](02_TheaterReservation/main.c) | [해설 MD](02_TheaterReservation/EXPLANATION.md) | [main.c](Applied_8to11/02_TheaterReservation/main.c) | [해설 MD](Applied_8to11/02_TheaterReservation/EXPLANATION.md) |
| ③ 배열 생성·정렬·탐색 | [main.c](03_ArraySearch/main.c) · [function.c](03_ArraySearch/function.c) · [function.h](03_ArraySearch/function.h) | [해설 MD](03_ArraySearch/EXPLANATION.md) | [main.c](Applied_8to11/03_ArraySearch/main.c) · [function.c](Applied_8to11/03_ArraySearch/function.c) · [function.h](Applied_8to11/03_ArraySearch/function.h) | [해설 MD](Applied_8to11/03_ArraySearch/EXPLANATION.md) |

~~~text
2ndSemesterClanguage/
├─ README.md
├─ 01_ScoreArray/                  1차 완성본 그대로 유지
│  ├─ main.c
│  └─ EXPLANATION.md
├─ 02_TheaterReservation/          1차 완성본 그대로 유지
│  ├─ main.c
│  └─ EXPLANATION.md
├─ 03_ArraySearch/                 1차 완성본 그대로 유지
│  ├─ main.c
│  ├─ function.c
│  ├─ function.h
│  └─ EXPLANATION.md
└─ Applied_8to11/                 별도로 새로 만든 응용판
   ├─ 01_ScoreArray/
   │  ├─ main.c
   │  └─ EXPLANATION.md
   ├─ 02_TheaterReservation/
   │  ├─ main.c
   │  └─ EXPLANATION.md
   └─ 03_ArraySearch/
      ├─ main.c
      ├─ function.c
      ├─ function.h
      └─ EXPLANATION.md
~~~

별도의 Visual Studio 솔루션 파일(.sln), 프로젝트 파일(.vcxproj), 실행 파일(.exe), 디버그 파일은 넣지 않았습니다. **C 소스와 해설 Markdown만** 보관합니다.

## 2. 원본과 응용판의 차이

### ① 점수 배열

- **원본**: 5명 점수 입력 → 정수 배열에 저장 → 차례로 출력.
- **응용판**: 입력과 출력 함수를 따로 작성하고 합계, 평균, 최고점 계산 함수를 추가했습니다. 점수의 사용 목적과 자연스럽게 연결됩니다.
- **중점 학습**: 8장 함수 반환값·매개변수, 10장 배열, 11장 배열과 함수의 연결.

### ② 영화관 예약

- **원본**: 10개 좌석에서 예약 의사 확인 → 좌석 선택 → 중복·범위 검사.
- **응용판**: 좌석 출력, 남은 좌석 계산, 예약 판정 함수를 별도로 사용합니다. 예약 결과를 1(성공), 0(중복), -1(잘못된 번호)로 구별합니다.
- **중점 학습**: 8장 함수·return, 10장 배열, 11장 배열을 함수에 전달하는 관계.

### ③ 난수 배열·정렬·탐색

- **원본**: 난수 생성 → 정렬 전 출력 → 선택 정렬 → 정렬 후 출력 → 이진 탐색. main.c, function.c, function.h의 세 파일로 나뉩니다.
- **응용판**: 정렬 **전 순차 탐색**을 추가하고, 정렬 **후 이진 탐색**과 비교합니다. 검색 함수는 찾은 **배열 인덱스 또는 -1**을 반환합니다.
- **중점 학습**: 8장 함수와 파일별 역할, 10장 배열·선택 정렬·순차·이진 탐색, 11장 배열 전달.

## 3. 8~11장 개념을 어떻게 적용했나?

| 단원 | 학습 주제 | 적용한 부분 |
|---|---|---|
| **8장** | 함수의 선언·정의·호출, 매개변수, 반환값 | 세 응용 프로그램의 독립된 함수들 |
| **9장** | 변수 범위와 재귀 호출 | **필요하지 않은 재귀는 억지로 사용하지 않음**. 각 함수 안의 일반 변수만 사용 |
| **10장** | 배열, 탐색, 정렬 | 점수 및 좌석 배열, 난수 배열의 정렬·탐색 |
| **11장** | 포인터와 배열의 관계 | scanf의 주소 연산자(&), 배열을 함수에 전달해 원래 배열 원소 사용 |

이 저장소에서는 **전역변수, 동적 메모리 할당, 구조체, 복잡한 포인터 연산, 재귀를 위한 인위적인 알고리즘**을 쓰지 않았습니다. 다만 함수 내부에서 선언하는 일반 변수는 C 프로그램 작성에 필요한 것이며, 정확한 용어로는 *지역변수*입니다. 변수 범위에 관한 어려운 응용을 사용하지 않았다는 의미입니다.

## 4. 실행 방법

### GCC 같은 C 컴파일러를 사용할 때

각 폴더에서 다음처럼 실행 파일을 만듭니다.

**점수 배열 (원본 또는 응용판 폴더 각각):**

~~~bash
gcc -std=c11 -Wall -Wextra main.c -o score
~~~

**영화관 좌석 예약 (원본 또는 응용판 폴더 각각):**

~~~bash
gcc -std=c11 -Wall -Wextra main.c -o theater
~~~

**배열 정렬·탐색 (원본 또는 응용판 폴더 각각):**

~~~bash
gcc -std=c11 -Wall -Wextra main.c function.c -o arraysearch
~~~

macOS/Linux에서는 `./score`, `./theater`, `./arraysearch`로 실행할 수 있으며 Windows에서는 `score.exe`처럼 실행합니다. **.h는 함수 선언을 포함하므로 컴파일 명령의 별도 소스 입력에 넣을 필요가 없습니다.**

### Visual Studio 2022에서 실행할 때

원하는 폴더의 C 소스만 새 **빈 C/C++ 프로젝트**에 추가하면 됩니다. 프로젝트 파일은 저장소에 올리지 않았습니다.

- 단일 파일 과제: `main.c` 하나만 추가.
- 배열 정렬·탐색 과제: `main.c`와 `function.c`를 소스 파일로, `function.h`를 헤더 파일로 함께 추가.
- **원본과 응용판 코드를 같은 프로젝트에 동시에 넣지 마세요.** 두 폴더 모두 main 함수를 가지고 있어서 main 중복 정의 오류가 납니다.
- 새 프로젝트의 파일 확장자는 **.c**로 유지하세요. 이 저장소는 C언어용입니다.

## 5. 공부하는 방법

1. 먼저 **원본 코드**를 직접 읽고 어떤 순서로 실행되는지 설명해 봅니다.
2. 같은 폴더의 **EXPLANATION.md**를 읽어 각 함수·조건·반복이 필요한 이유를 확인합니다.
3. 코드를 가리고 **교수님 예상 질문**에 스스로 말로 답해 봅니다.
4. **응용판**을 실행해 무엇이 바뀌었는지 비교합니다.
5. 응용판의 **EXPLANATION.md**에서 바뀐 이유, 배열 인자의 의미, 반환값을 확인합니다.
6. 실제 실행에서 숫자를 다르게 넣어 보며 출력과 배열의 변화를 예측해 봅니다.

핵심은 이름과 문법만 외우는 것이 아니라 **왜 배열이 필요한가, 왜 함수로 나누었는가, 왜 정렬 후 이진 탐색인가**를 자신의 말로 설명하는 것입니다.

## 6. 테스트 시 확인할 사항

- 점수 프로그램: 5개 점수가 저장·출력되는지, 응용판에서 0~100 범위를 검사하고 합계·평균·최고점을 계산하는지.
- 영화관 프로그램: 1번과 10번의 예약, 이미 예약된 자리, 0번 및 11번, 만석 상태가 처리되는지.
- 배열 프로그램: 난수 10개 출력, 오름차순 정렬, 배열에 있는 수 검색, 없는 수 검색, 순차/이진 탐색 결과가 맞는지.
- 세 프로그램은 콘솔 입력이 필요하며 재시작하면 저장된 점수나 예약 상태는 사라집니다.

> 이 문서의 예시 실행 결과는 이해를 돕기 위한 것입니다. 특히 난수는 실행할 때마다 바뀝니다. 실제 제출 전에는 자신의 Visual Studio 2022 환경에서 직접 빌드·실행하고 코드의 모든 부분을 설명할 수 있는지 확인하세요.
